#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    for (int i = 0; i < M; i++) cin >> a[i];

    vector<long long> b(N);
    for (int i = 0; i < N; i++) cin >> b[i];

    const long long NEG = -4e18;
    vector<long long> dp(N, NEG);
    dp[0] = 0;

    long long ans = NEG;

    for (int x = 0; x < N; x++) {
        if (dp[x] == NEG) continue;  // 无法到达

        for (int i = 0; i < M; i++) {
            int nx = x + a[i];
            long long val = dp[x] + b[x];  // 离开 x 时获得 b[x]

            if (nx >= N) {
                ans = max(ans, val);  // 通关
            } else {
                dp[nx] = max(dp[nx], val);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
