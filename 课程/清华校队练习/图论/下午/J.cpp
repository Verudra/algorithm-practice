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
bool vis[N][N];
char mp[N][N];
int px[] = {-1,1,0,0}, py[] = {0,0,-1,1};
int ts = 0, tcir = 0;
int n; 
void dfs(int x,int y){
    ts ++;
    vis[x][y] = 1;
    rep(i,4){
        int tx = x+px[i], ty = y+py[i];
        if((tx<=0||tx>n||ty<=0||ty>n)||mp[tx][ty]=='.') tcir++;
        if(!vis[tx][ty]&&mp[tx][ty]=='#') dfs(tx,ty);
    }
}
void work(){
    cin >> n;
    For(i,1,n){
        For(j,1,n){
            cin >> mp[i][j];
        }
    }
    int mxs = -INF, mxcir = -INF;
    For(i,1,n){
        For(j,1,n){
            if(mp[i][j] == '#' && !vis[i][j]){
                ts = tcir = 0;
                dfs(i,j);
                if(mxs < ts) mxs = ts, mxcir = tcir;
                else if(mxs == ts) mxcir = min(mxcir, tcir);
            }
        }
    }
    cout << mxs << ' ' << mxcir;
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