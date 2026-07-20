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
const int N = 10;
int mp[N][N];
int dp[N][N][N][N];
int n; 
int dfs(int x1,int y1,int x2,int y2){
    if(x1 > n || y1 > n || x2 > n || y2 > n) return 0;
    if(x1==n&&y1==n) return mp[n][n];
    int& res = dp[x1][y1][x2][y2];
    if(res != -1) return res;
    int cur = mp[x1][y1];
    if(x1 != x2 || y1 != y2){
        cur += mp[x2][y2];
    }
    int nxres = max({
        dfs(x1+1,y1,x2+1,y2),
        dfs(x1,y1+1,x2+1,y2),
        dfs(x1+1,y1,x2,y2+1),
        dfs(x1,y1+1,x2,y2+1)
    });
    return res = cur+nxres;
}
void work(){
    cin >> n;
    int x,y,v;
    while(cin >> x >> y >> v){
        if(x == y && y == v && v == 0) break;
        mp[x][y] = v;
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(1,1,1,1);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}