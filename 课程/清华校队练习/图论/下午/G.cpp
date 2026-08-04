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
const int N = 25;
int n,m; 
char mp[N][N];
bool vis[N][N];
int px[] = {-1,1,0,0}, py[] = {0,0,-1,1};
void work(){
    memset(vis,0,sizeof(vis));
    int sx, sy;
    For(i,1,n) For(j,1,m) {
        cin >> mp[i][j];
        if(mp[i][j] == '@'){
            sx = i; sy = j;
        }
    }
    struct node{
        int x,y,cnt;
    };
    queue<node> q;
    q.push({sx,sy,0});
    while(!q.empty()){
        auto t = q.front(); q.pop();
        if(mp[t.x][t.y] == '*'){
            cout << t.cnt << '\n';
            return ;
        }
        rep(i,4){
            int tx = px[i]+t.x, ty = py[i]+t.y;
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if((mp[tx][ty] == '*' || mp[tx][ty] == '.') && !vis[tx][ty]){
                q.push({tx,ty,t.cnt+1});
                vis[tx][ty] = true;
            }
        }
    }
    cout << -1 << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int T=1; 
    //cin >> T;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        work();
    }
    return 0;
}