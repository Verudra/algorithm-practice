#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int ans[N];
int n;
void dfs(int u){
    if(u > n){
        for(int i = 1;i <= n;i ++) cout << ans[i] << (i==n?'\n':' ');
        return ;
    }
    for(int i = 1;i <= n;i ++){
        ans[u] = i;
        dfs(u+1);
    }
    return ;
}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}