#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = (s[j - 1] == '1');  // 黑色为 1
        }
    }

    // 二维前缀和 sum[i][j] = (1,1) 到 (i,j) 的黑格数量
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1]
                      - sum[i - 1][j - 1] + a[i][j];
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
        return sum[x2][y2] - sum[x1 - 1][y2]
             - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    };

    int ans = INT_MAX;

    // 枚举所有子矩形
    for (int x1 = 1; x1 <= n; x1++) {
        for (int x2 = x1; x2 <= n; x2++) {
            for (int y1 = 1; y1 <= m; y1++) {
                for (int y2 = y1; y2 <= m; y2++) {
                    int blacks = get(x1, y1, x2, y2);
                    if (blacks >= k) {
                        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                        ans = min(ans, area);
                    }
                }
            }
        }
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans << "\n";

    return 0;
}
