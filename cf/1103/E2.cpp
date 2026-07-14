#include <bits/stdc++.h>
using namespace std;

void work() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int ans = 0;
    int maxLen = n / 2;

    vector<vector<char>> good(maxLen + 1, vector<char>(n + 2, 0));

    for (int l = 0; l < n; l++) {
        vector<int> cnt(n + 1, 0);

        int distinct = 0;
        int mn = n + 1;
        int mx = 0;

        for (int r = l; r < n && r - l + 1 <= maxLen; r++) {
            int x = a[r];
            int len = r - l + 1;

            if (++cnt[x] == 1) distinct++;

            mn = min(mn, x);
            mx = max(mx, x);

            if (distinct == len && mx - mn + 1 == len) {
                if (mn - len >= 1 && good[len][mn - len]) {
                    ans = max(ans, len);
                }

                if (mn + len <= n && good[len][mn + len]) {
                    ans = max(ans, len);
                }

                good[len][mn] = 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        work();
    }

    return 0;
}