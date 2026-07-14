#include <bits/stdc++.h>
using namespace std;
const int N = 35;
struct node{
    int l,r,w;
}tre[N];
int cnt[N];
int mdep = 0;
void dfs(int u,int dep){
    mdep = max(mdep, dep);
    cnt[dep] ++;
    auto& t = tre[u];
    if(t.l) dfs(t.l,dep+1);
    if(t.r) dfs(t.r,dep+1);
}
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int u; cin >> u;
        auto& t = tre[u];
        cin >> t.l >> t.r;
    }
    dfs(1,1);
    int mlen = 0;
    for(int i = 1;i <= n;i ++) mlen = max(mlen, cnt[i]);
    cout << mdep << ' ' << mlen;
    return 0;
}