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
#define len(s) ((int)s.size())
#define se second
#define vpii vector<pair<int, int>>
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work()
{
    int n;
    cin >> n;
    vpii v0, v1;
    rep(i, n)
    {
        int t;
        cin >> t;
        if (t <= 0)
            v0.push_back({t, i});
        else
            v1.push_back({t, i});
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end(), [](pii a, pii b)
         { return a > b; });
    int pos = 0;
    int ans = 0;
    while (!v0.empty() && !v1.empty())
    {
        auto [val0, id0] = v0.back();
        auto [val1, id1] = v1.back();
        int disl = abs(val0 - pos), disr = abs(val1 - pos);
        int flag = (disl < disr ? -1 : disl == disr ? 0
                                                    : 1);
        if (flag == -1 || flag == 0)
        {
            ans += abs(val0 - pos);
            pos = val0;
            v0.pop_back();
        }
        else if (flag == 1)
        {
            ans += abs(val1 - pos);
            pos = val1;
            v1.pop_back();
        }
    }
    while (!v0.empty())
    {
        ans += abs(v0.back().first - pos);
        pos = v0.back().first;
        v0.pop_back();
    }
    while (!v1.empty())
    {
        ans += abs(v1.back().first - pos);
        pos = v1.back().first;
        v1.pop_back();
    }
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