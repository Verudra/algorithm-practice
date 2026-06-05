#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int n,k;
void dfs(int u){
    // cout << u << '\n';
    if(u<=k || (u-k)&1){
        ans ++;
        return ;
    }
    int l = u-k>>1, r = u-l;
    dfs(l);
    dfs(r);
}
int main(){
    cin >> n >> k;
    dfs(n);
    cout << ans;
    return 0;
}