#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 60;
int ene[N][N], beni[N][N];
int dp[N][N][N];
bool vis[N][N][N];
int n,m,K,E;
int dfs(int x,int y,int e){
    if(x > n || y > m || e < 0 || e > K) return -INF;
    if(x == n && y == m) return beni[x][y];
    if(vis[x][y][e]) return dp[x][y][e];
    vis[x][y][e] = true;
    int tb = beni[x][y];
    dp[x][y][e] = tb+max(dfs(x+1,y,e+ene[x+1][y]),dfs(x,y+1,e+ene[x][y+1]));
    return dp[x][y][e];
}
void work(){    
    cin >> n >> m >> K >> E;
    memset(dp,-0x3f,sizeof dp);
    For(i,1,n){
        For(j,1,m){
            cin >> ene[i][j];
        }
    }
    For(i,1,n){
        For(j,1,m) cin >> beni[i][j];
    }
    int ans = dfs(1,1,E+ene[1][1]);
    cout << (ans<=-INF/2?-1:ans);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}