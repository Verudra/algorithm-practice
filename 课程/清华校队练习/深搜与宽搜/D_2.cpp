#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int sa[N];
int n;
bool vis[N*10005];
vector<int>ans;
void dfs(int now,int sum){
    if(now == n+1){
        if(!vis[sum]){
            vis[sum] = true;
            ans.push_back(sum);
            return ;
        }
        return ;
    }
    dfs(now+1,sum+sa[now]);
    dfs(now+1,sum);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    dfs(1,0);
    sort(ans.begin(),ans.end());
    for(auto i : ans) if(i) cout << i << ' ';
    return 0;
}