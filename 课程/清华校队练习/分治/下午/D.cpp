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
int cnt = 1;
const int N = 1<<10;
int mp[N][N];
void dfs(int lx,int ly,int k,int px,int py){
    if(k == 0) return ;
    int len = 1<<k-1;
    int h1x = lx+len-1, h1y = ly+len-1;
    int h2x = lx+len-1, h2y = ly+len;
    int h3x = lx+len, h3y = ly+len-1;
    int h4x = lx+len, h4y = ly+len;
    if(px >= lx+len){
        if(py >= ly+len){
            h4x = px, h4y = py;
            mp[lx+len-1][ly+len-1] = 4;
        }else{
            h3x = px, h3y = py;
            mp[lx+len-1][ly+len] = 3;
        }
    }
    else{
        if(py >= ly+len){
            h2x = px, h2y = py;
            mp[lx+len][ly+len-1] = 1;
        }
        else{
            h1x = px, h1y = py;
            mp[lx+len][ly+len] = 2;
        }
    }
    dfs(lx,ly,k-1,h1x,h1y);
    dfs(lx,ly+len,k-1,h2x,h2y);
    dfs(lx+len,ly,k-1,h3x,h3y);
    dfs(lx+len,ly+len,k-1,h4x,h4y);
}
void work(){
    int k,x,y; cin >> k >> x >> y;
    mp[x][y] = -1;
    dfs(1,1,k,x,y);
    For(i,1,1<<k){ 
        For(j,1,1<<k) cout << mp[i][j] << ' ';
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