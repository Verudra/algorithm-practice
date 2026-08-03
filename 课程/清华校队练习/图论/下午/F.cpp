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
const int N = 55;
char mp[N][N];
int n,k; 
bool vis[N];
int V[N],cnt;
void dfs(int u){
    cnt ++;
    vis[u] = true;
    For(i,1,n) if(mp[u][i]=='1'&&!vis[i]) dfs(i);
    return ;
}
int C2(int x){
    return x*(x-1)/2;
}
void work(){
    cin >> n;
    int edgcnt = 0;
    For(i,1,n) For(j,1,n) {cin >> mp[i][j]; if(mp[i][j] == '1') edgcnt ++;}
    edgcnt /= 2;
    int ans = 0,mx = 0;
    cin >> k;
    For(i,1,k){
        cnt = 0;
        cin >> V[i]; V[i] ++;
        dfs(V[i]);
        mx = max(mx,cnt);
        ans += C2(cnt);
    }
    int free = 0;
    For(i,1,n) if(!vis[i]){
        cnt = 0;
        dfs(i);
        free += cnt;
    }
    ans += C2(free+mx)-C2(mx);
    cout << ans-edgcnt;
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