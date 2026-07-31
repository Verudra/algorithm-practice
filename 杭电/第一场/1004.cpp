#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#include<queue>
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
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 2e5+10;
int fa[N],siz[N],va[N],vb[N];
int getfa(int u){
    return u == fa[u]?u:fa[u] = getfa(fa[u]);
}
void init(int n,const vector<int>&v1,const vector<int>&v2){
    for(int i = 1;i <= n;i ++){
        fa[i] = i;
        siz[i] = 1;
        va[i] = v1[i];
        vb[i] = v2[i];
    }
    return ;
}
void uni(int a,int b){
    int faa = getfa(a),fab = getfa(b);
    if(faa == fab) return ;
    fa[faa] = fab;
    siz[fab] += siz[faa];
    vb[fab] += vb[faa];
    va[fab] += va[faa];
    return ;
}

struct Edge{
    int nxt,to,w;
}edg[N<<1];
int head[N], tot, rd[N];

void init_graph(int _n){
    tot = 0;
    For(i,1,_n) head[i] = rd[i] = 0;
    return ;
}

void add(int u,int v,int w=0){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    edg[tot].w = w;
    head[u] = tot;
    rd[v] ++;
}

void work(){
    int n; cin >> n;
    vi a(n+1),b(n+1);
    For(i,1,n) cin >> a[i];
    For(i,1,n) cin >> b[i];
    init_graph(n);
    init(n,a,b);
    For(i,1,n){
        int f; cin >> f;
        if(f == 0) continue;
        add(i,f);
    }
    struct node{
        int id,a,b;
        bool operator<(const node& t)const{
            __int128 x = (__int128)b*t.a;
            __int128 y = (__int128)a*t.b;
            if(x != y) return x > y;
            return id > t.id;
        }
    };
    priority_queue<node>pq;
    For(i,1,n) pq.push({i,a[i],b[i]});
    int sum = 0;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        int ft = getfa(t.id);
        if(t.id != ft) continue;
        if(t.a != va[ft] || t.b != vb[ft]) continue;
        if(head[ft] == 0) continue;
        int to = edg[head[ft]].to;
        int tfa = getfa(to);
        // if(ft == tfa) continue; // 这个必须判断吗？
        sum += va[ft]*vb[tfa];
        uni(ft,tfa);

        int id = getfa(ft);
        pq.push({id,va[id],vb[id]});
    }
    cout << sum << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T --) work();
    return 0;
}