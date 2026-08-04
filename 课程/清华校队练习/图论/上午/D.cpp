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
const int N = 2e5;
vvi vec(N);
bool vis[N];
void work(){
    int n,m,s; cin >> n >> m >> s;
    For(i,1,m){
        int u,v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    queue<int>q; vis[s] = true;
    q.push(s);
    while(!q.empty()){
        int t = q.front(); q.pop();
        cout << t << ' ';
        for(auto to : vec[t]){
            if(vis[to]) continue;
            q.push(to);
            vis[to] = true;
        }
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