#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int tre[N<<2];
void dfs1(int u){
    if(!tre[u]) return ;
    cout << tre[u] << ' ';
    dfs1(u<<1); dfs1(u<<1|1);
    return ;
}
void dfs2(int u){
    if(!tre[u]) return ;
    dfs2(u<<1);
    cout << tre[u] << ' ';
    dfs2(u<<1|1);
    return ;
}
void dfs3(int u){
    if(!tre[u]) return ;
    dfs3(u<<1);
    dfs3(u<<1|1);
    cout << tre[u] << ' ';
    return ;
}
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++) cin >> tre[i];
    dfs1(1); cout << '\n'; dfs2(1); cout << '\n'; dfs3(1);
    return 0;
}