#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int fa[N];
int gfa(int u){
    if(u == fa[u]) return u;
    return fa[u] = gfa(fa[u]);
}
void uni(int u,int v){
    fa[gfa(u)] = gfa(v);
}
int main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++){
        int z,x,y;
        cin >> z >> x >> y;
        if(z == 1) uni(x,y);
        else{
            if(gfa(x)==gfa(y)) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}