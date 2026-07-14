#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int>v(1,1);
    map<int,bool>mp;
    cin >> n; n --; mp[1] = true;
    while(n --){
        int k = v.size()+1;
        int l = v.back()-k, r = v.back()+k;
        if(l > 0 && !mp[l]){
            mp[l] = true;
            v.push_back(l);
        }
        else{
            mp[r] = true;
            v.push_back(r);
        }
    }
    sort(v.begin(),v.end());
    for(auto i : v) cout << i << ' ';
    return 0;
}