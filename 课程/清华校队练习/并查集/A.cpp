#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int fa[N];
int gfa(int u){
    if(u == fa[u]) return u;
    return fa[u] = gfa(fa[u]);
}
void uni(int u,int v){
    fa[gfa(u)] = gfa(v);
}
int main(){
    int n,m,p;
    cin >> n >> m >> p;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++){
        int u,v;
        cin >> u >> v;
        uni(u,v);
    }
    for(int i = 1;i <= p;i ++){
        int u,v;
        cin >> u >> v;
        if(gfa(u)==gfa(v)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}