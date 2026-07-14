#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
    int n,m;cin >> n >> m;
    int ans = 0;
    for(int i = 1;i <= m;i ++){
        string s1,s2; cin >> s1 >> s2;
        mp[s1] ++; mp[s2] ++;
        ans = max({ans,mp[s1],mp[s2]});
    }
    cout << ans;
    return 0;
}