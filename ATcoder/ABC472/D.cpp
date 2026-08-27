#include <bits/stdc++.h>
#define int ll
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n) - 1; i >= 0; i--)
#define For(i, l, r) for (int i = (l); i <= (r); i++)
#define Rof(i, l, r) for (int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define fi first
#define se second
#define vpii vector<pair<int, int>>
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void work()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> mp(h + 1, vector<char>(w + 1));
    vector<bool> visx(h + 1), visy(w + 1);
    vvi dp(h + 1, vi(w + 1, INF));
    For(i, 1, h) For(j, 1, w)
    {
        cin >> mp[i][j];
        if (mp[i][j] == '#')
            visx[i] = visy[j] = true;
    }
    struct node
    {
        int x, y, cnt;
    };
    queue<node> q;
    For(i, 1, h) For(j, 1, w) if (!visx[i] && !visy[j]) q.push({i, j, 0}), dp[i][j] = 0;
    while (!q.empty())
    {
        auto [x, y, cnt] = q.front();
        q.pop();
        rep(o, 4)
        {
            int tx = dx[o] + x, ty = dy[o] + y;
            if (tx >= 1 && tx <= h && ty >= 1 && ty <= w && mp[tx][ty] == '.')
            {
                if (dp[tx][ty] > cnt + 1)
                {
                    dp[tx][ty] = cnt + 1;
                    q.push({tx, ty, cnt + 1});
                }
            }
        }
    }
    int ans = 0;
    For(i, 1, h) For(j, 1, w) if (dp[i][j] <= k) ans++;
    cout << ans;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        work();
    return 0;
}