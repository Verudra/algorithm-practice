#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string sa[N];
bool vis[N];
int ans = 0;
int n;
void dfs(char c,int cnt){
    ans = max(ans,cnt);
    for(int i = 1;i <= n;i ++){
        if(!vis[i] && c==sa[i][0]){
            vis[i] = true;
            dfs(sa[i][1],cnt+1);
            vis[i] = false;
        }
    }
    return ;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    vis[1] = true;
    dfs(sa[1][1],1);
    cout << ans;
    return 0;
}
