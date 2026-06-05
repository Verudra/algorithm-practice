#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int sa[N];
int n;
bool vis[N];
int ans = 1e9;
void dfs(int u,int sum,int l){
    if(u >= n){
        ans = min(ans,sum);
        return ;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            vis[i] = true;
            dfs(u+1,sum+abs(l-sa[i]/10)+abs(sa[i]/10-sa[i]%10),sa[i]%10);
            vis[i] = false;
        }
    }
    return ;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    for(int i = 1;i <= n;i ++){
        vis[i] = true;
        dfs(1,abs(sa[i]/10-sa[i]%10),sa[i]%10);
        vis[i] = false;
    }
    cout << ans;
    return 0;
}