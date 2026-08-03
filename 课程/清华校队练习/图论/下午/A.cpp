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
map<string,int>mp;
const int N = 2e5+10;
int cnt = 0;
struct Edge{
    int nxt,to,w;
}edg[N<<1];
int head[N],tot,rd[N];
void init_graph(int n){
    tot = 0;
    for(int i = 1;i <= n;i ++){
        head[i] = rd[i] = 0;
    }
    return ;
}
void add(int u,int v,int w=0){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    edg[tot].w = w;
    head[u] = tot;
    rd[v] ++;
    return ;
}
int id(string s){
    if(mp.count(s) == 0) return mp[s] = ++cnt;
    return mp[s];
}
void add(string s1,string s2){
    add(id(s1),id(s2));
}
void work(){
    int n,m; cin >> n >> m;
    For(i,1,m){
        string s1,s2; cin >> s1 >> s2;
        add(s1,s2);
        add(s2,s1);
    }
    int mx = 0;
    For(i,1,n) mx = max(mx, rd[i]);
    cout << mx;
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