#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
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
const int N = 1005;
char mp[N][N];
bool vis[N][N];
int px[] = {-1,1,0,0}, py[] = {0,0,-1,1};
int cnts,cntdot;
void dfs(int x,int y,char c){
    vis[x][y] = true;
    cnts ++;
    rep(i,4){
        int tx = x+px[i], ty = y+py[i];
        if(mp[tx][ty] == '.') cntdot ++;
        if(mp[tx][ty] == c && !vis[tx][ty]) dfs(tx,ty,c);
    }
}
void work(){
    int n,m; cin >> n >> m;
    For(i,1,n) For(j,1,m) cin >> mp[i][j];
    int ansZ = 0, ansQ = 0;
    For(i,1,n){
        For(j,1,m){
            if(mp[i][j]!='.'&&!vis[i][j]){
                cnts = cntdot = 0;
                dfs(i,j,mp[i][j]);
                if(cnts >= 3 && cntdot > 0){
                    ansZ ++; ansQ += cnts;
                }
            }
        }
    }
    cout << ansZ << ' ' << ansQ;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}