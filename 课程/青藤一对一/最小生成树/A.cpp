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
const int N = 2e5+10;
int fa[N],siz[N];
int getfa(int u){
    return u == fa[u]?u:fa[u] = getfa(fa[u]);
}
void init(int n){
    for(int i = 1;i <= n;i ++){
        fa[i] = i;
        siz[i] = 1;
    }
    return ;
}
void uni(int a,int b){
    int faa = getfa(a),fab = getfa(b);
    if(faa == fab) return ;
    if(siz[faa] > siz[fab]) swap(faa,fab);
    fa[faa] = fab;
    siz[fab] += siz[faa];
    return ;
}

void work(){
    int n,m; cin >> n >> m;
    init(n);
    For(i,1,m){
        int z,x,y; cin >> z >> x >> y;
        if(z == 1){
            uni(x,y);
        }else{
            if(getfa(x) == getfa(y)) cout << "Y\n";
            else cout << "N\n";
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