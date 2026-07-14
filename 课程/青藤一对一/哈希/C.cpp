#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int>mp;
    int n; cin >> n;
    vector<int>v;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        mp[t] ++;
        if(mp[t] == 1) v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(auto i : v) cout << i << ' ' << mp[i] << '\n';
    return 0;
}