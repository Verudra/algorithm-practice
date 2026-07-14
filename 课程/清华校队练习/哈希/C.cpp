#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int main(){
    int n;cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        mp[t] ++;
    }
    vector<pair<int,int> > v;
    for(auto p : mp){
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(auto p : v){
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}