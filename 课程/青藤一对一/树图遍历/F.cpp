#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> vec[N];
void dfs(int u,int fa){
    cout << u << ' ';
    for(auto i : vec[u]){
        if(fa == i) continue;
        dfs(i, u);
        cout << u << ' ';
    }
    return ;
}
int main(){
    int n,k; cin >> n >> k;
    for(int i = 1;i < n;i ++){
        int u,v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(k,0);
    return 0;
}