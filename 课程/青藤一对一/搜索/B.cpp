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
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int n,m,x,y; 
bool vis[25][25];
int dp[30][30];
int dfs(int x,int y){
    if(x == n && y == m) return 1;
    if(vis[x][y]) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    if(x < 0 || x > n || y < 0 || y > m) return 0;
    return dp[x][y] = dfs(x+1,y) + dfs(x,y+1);
}
void work(){
    cin >> n >> m >> x >> y;
    int tx[] = {-1,-2,-2,-1,1,2,2,1,0};
    int ty[] = {-2,-1,1,2,2,1,-1,-2,0};
    For(i,0,8){
        vis[x+tx[i]][y+ty[i]] = true;
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}