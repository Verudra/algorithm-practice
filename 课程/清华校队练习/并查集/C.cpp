#include <bits/stdc++.h>
using namespace std;
bool F = true;
const int N = 1005;
int fa[N];
int gfa(int u){
    if(u == fa[u]) return u;
    return fa[u] = gfa(fa[u]);
}
void uni(int u,int v){
    fa[gfa(u)] = gfa(v);
}
void init(int n){
    for(int i = 1;i <= n;i ++) fa[i] = i;
}
void wk(){
    int n,m;
    cin >> n; if(!n){F=false;return ;}
    cin >> m;
    init(n);
    for(int i = 1;i <= m;i ++){
        int u,v; cin >> u >> v;
        uni(u,v);
    }
    int ans = 0;
    for(int i = 2;i <= n;i ++){
        if(gfa(i) != gfa(i-1)){
            uni(i,i-1);
            ans ++;
        }
    }
    cout << ans << '\n';
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(F){
        wk();
    }
    return 0;
}