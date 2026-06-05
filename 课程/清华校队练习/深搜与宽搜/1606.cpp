#include <bits/stdc++.h>
using namespace std;
const int N = 15;
bool vis[N];
int m,n,k;
int ans;
void dfs(int cnt1,int cnt2){
    if(cnt1 + cnt2 >= m){
        ans ++;
        return ;
    }
    if(cnt1 > cnt2){
        for(int i = n+1;i <= m;i ++){
            if(!vis[i]){
                vis[i] = true;
                dfs(cnt1, cnt2+1);
                vis[i] = false;
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            vis[i] = true;
            dfs(cnt1+1,cnt2);
            vis[i] = false;
        }
    }
    return ;
}
int main(){
    cin >> m >> n >> k;
    dfs(0,0);
    cout << ans;
    return 0;
}