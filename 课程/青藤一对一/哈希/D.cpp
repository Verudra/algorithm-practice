#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin >> n >> c;
    unordered_map<int,int>mp;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t; mp[t] ++;
    }
    long long ans = 0;
    for(auto [k,v] : mp){
        if(mp.count(k+c)) ans += 1ll*mp[k+c]*v;
    }
    cout << ans;
    return 0;
}