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
const int N = 105;
char mp[N][N];
bool vis[N][N];
int px[] = {-1,-1,-1,0,0,0,1,1,1}, py[] = {-1,0,1,-1,0,1,-1,0,1};
void work(){
    int n,m; cin >> n >> m;
    For(i,1,n) For(j,1,m) cin >> mp[i][j];
    int sx,sy; cin >> sx >> sy;
    queue<pii> q; q.push({sx,sy}); vis[sx][sy] = 1;
    while(!q.empty()){
        auto t = q.front(); q.pop();
        rep(i,9){
            int tx = t.first+px[i], ty = t.second+py[i];
            if(vis[tx][ty] == 0 && mp[tx][ty] == '1') {q.push({tx,ty});vis[tx][ty] = 1;}
            mp[tx][ty] = '2';
        }
    }
    For(i,1,n){
        For(j,1,m) cout << mp[i][j];
        cout << '\n';
    }
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