#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int sz[N];
vector<int>ans;
vector<int>v;
void dfs(int u){
    sz[u] ++;
    if(!v[u]){
        ans.push_back(v[u]);
        return ;
    }
    dfs(u+1); sz[u] += sz[u+1];
    ans.push_back(v[u]);
    dfs(u+sz[u]); sz[u] += sz[u+sz[u]];
    return ;
}
int main(){
    int t;
    while(cin >> t) v.push_back(t);
    dfs(0);
    for(auto i : ans) cout << i << ' ';
    return 0;
}