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
#define len(s) ((int)s.size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 2e5 + 10;
struct Edge
{
    int nxt, to, w;
} edg[N << 1];
int head[N], tot, rd[N];
void init_graph(int n)
{
    tot = 0;
    for (int i = 1; i <= n; i++)
    {
        head[i] = rd[i] = 0;
    }
    return;
}
void add(int u, int v, int w = 0)
{
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    edg[tot].w = w;
    head[u] = tot;
    rd[v]++;
    return;
}
void dfs(int u, vector<bool> &vis, vi &path)
{
    path.push_back(u);
    for (int e = head[u]; e; e = edg[e].nxt)
    {
        int to = edg[e].to;
        if (vis[to])
            continue;
        vis[to] = true;
        dfs(to, vis, path);
    }
}
void work()
{
    int n, m;
    cin >> n >> m;
    init_graph(n);
    vector<bool> vis(n + 1);
    For(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    queue<int> q;
    For(i, 1, n) if (rd[i] == 1) q.push(i), vis[i] = true;
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        for (int e = head[t]; e; e = edg[e].nxt)
        {
            int to = edg[e].to;
            if (vis[to])
                continue;
            rd[to]--;
            if (rd[to] == 1)
                q.push(to), vis[to] = true;
        }
    }
    For(i, 1, n) if (!vis[i])
    {
        vi v;
        vis[i] = true;
        dfs(i, vis, v);
        if (len(v) & 1)
        {
            cout << len(v) << '\n';
            for (auto j : v)
                cout << j << ' ';
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        work();
    return 0;
}