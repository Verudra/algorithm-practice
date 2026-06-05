#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int sa[N];
bool vis[N*10005];
// map<int,bool>mp;
int main(){
    int n;cin >> n;
    vector<int>ans;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    for(int i = 1;i <= (1<<n)-1;i ++){
        int s = 0;
        for(int j = 0;j < n;j ++){
            if((i&(1<<j))){
                s += sa[j+1];
            }
        }
        if(!vis[s]){
            ans.push_back(s);
            vis[s] = true;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i ++) {
        cout << ans[i] << ' ';
    }
    return 0;
}