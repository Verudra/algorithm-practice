#include<bits/stdc++.h>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
struct node1{
    int x,y;
};
const node1 D[] = {{-1,0},{1,0},{0,-1},{0,1}};
const int N = 1e3+10;
int ans[N][N][3];
void work(){
    // memset(ans,-1,sizeof(ans));
    int n,m; cin >> n >> m;
    For(i,1,n) For(j,1,m) For(k,0,2) ans[i][j][k] = -1;
    string s; cin >> s;
    vector<string>mp(n);
    rep(i,n) cin >> mp[i];
    struct node{int x,y,op;};
    auto gid = [&](node x){
        return ((x.x-1)*m + (x.y-1))*3+x.op;
    };
    queue<node>q;
    vector<bool> vis(n*m*3+1);
    ans[n][m][0] = ans[n][m][1] = ans[n][m][2] = 0;
    q.push({n,m,0}); q.push({n,m,1}); q.push({n,m,2});
    vis[gid({n,m,0})] = vis[gid({n,m,1})] = vis[gid({n,m,2})] = true;
    while(!q.empty()){
        auto t = q.front(); 
        int x = t.x, y = t.y, op = t.op;
        q.pop();
        rep(i,4){
            auto [dx,dy] = D[i];
            For(k,1,3){
                int tx = x+dx*k, ty = y+dy*k;
                auto check = [&](int x,int y){
                    if(tx>n || tx<1 || ty>m || ty<1) return false;
                    int pre = (op+2)%3;
                    int p = (pre+k-1)%3;
                    if(s[p] != mp[x-1][y-1]) return false;
                    return true;
                };
                if(check(x,y)){
                    node nxt = {tx,ty,(op+2)%3};
                    if(vis[gid(nxt)]) continue;
                    vis[gid(nxt)] = true;
                    q.push(nxt);
                    ans[tx][ty][(op+2)%3] = ans[x][y][op] + 1;
                }
            }
        }
    }
    For(i,1,n) For(j,1,m) cout << ans[i][j][0] << " \n"[j==m];
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}