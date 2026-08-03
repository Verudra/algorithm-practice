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
char mp[N][N];
int tim[N][N];
int px[] = {-1,1,0,0}, py[] = {0,0,-1,1};
void work(){
    int n,m; cin >> n >> m;
    struct node{
        int x,y,cnt;
    };
    memset(tim,-1,sizeof(tim));
    queue<node>q;
    For(i,1,n){
        For(j,1,m){
            cin >> mp[i][j];
            if(mp[i][j] == 'F'){
                q.push({i,j,0});
                tim[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto t = q.front(); q.pop();
        rep(i,4){
            int tx = t.x+px[i], ty = t.y+py[i];
            if(mp[tx][ty] == '.' && tim[tx][ty] == -1){
                q.push({tx,ty,t.cnt+1});
                tim[tx][ty] = t.cnt+1;
            }
        }
    }
    For(i,1,n){
        For(j,1,m){
            cout << tim[i][j] << ' ';
        }
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