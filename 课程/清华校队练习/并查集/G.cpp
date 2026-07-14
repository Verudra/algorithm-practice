#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int fa[N],eny[N];
int gfa(int u){
    if(u == fa[u]) return u;
    return fa[u] = gfa(fa[u]);
}
void uni(int u,int v){
    fa[gfa(u)] = gfa(v);
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++){
        char c; int u,v;
        cin >> c >> u >> v;
        if(c == 'E'){
            if(eny[u]) uni(v,eny[u]);
            if(eny[v]) uni(u,eny[v]);
            eny[u] = v;
            eny[v] = u;
        }
        else{
            uni(u,v);
        }
    }
    int ans = 1;
    for(int i = 2;i <= n;i ++){
        if(gfa(i) != gfa(i-1)){
            ans ++; uni(i,i-1);
        }
    }
    cout << ans;
    return 0;
}