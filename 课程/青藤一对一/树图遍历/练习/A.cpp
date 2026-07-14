#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node{
    int nxt,to;
}edg[N*2];
int tot,head[N],d[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
    d[u] ++;
}
int main(){
    int n; cin >> n;
    for(int i = 1;i < n;i ++){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        if(d[i] == 1) ans ++;
    }
    cout << ans;
    return 0;
}