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
const int N = 305;
int mp[N][N];
int px[] = {-1,1,0,0,0}, py[] = {0,0,-1,1,0};
bool vis[N][N];
void work(){
    int m; cin >> m;
    memset(mp,0x3f,sizeof mp);
    For(i,1,m){
        int x,y,t; cin >> x >> y >> t;
        x ++; y ++;
        rep(k,5){
            int tx = x+px[k], ty = y+py[k];
            mp[tx][ty] = min(mp[tx][ty], t);
        }
    }
    For(i,0,304) mp[0][i]=mp[i][0] = -1;
    // int sx = 1, sy = 1;
    struct node{
        int x,y,t;
    };
    queue<node>q; q.push({1,1,0});
    vis[1][1] = true;
    while(!q.empty()){
        auto t = q.front(); q.pop();
        if(mp[t.x][t.y] > INF/2){
            cout << t.t;
            return ;
        }
        rep(i,5){
            int tx = t.x+px[i], ty = t.y+py[i];
            if(mp[tx][ty] > t.t+1 && !vis[tx][ty]){
                vis[tx][ty] = true;
                q.push({tx,ty,t.t+1});
            }
        }
    }
    cout << -1;
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