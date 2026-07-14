#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull getid(string s){
    ull res = 0, base = 131;
    for(auto i : s) res = res*base + (ull)i;
    return res;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    vector<ull> v;
    for(int i = 1;i <= n;i ++){
        string s;cin >> s;
        v.push_back(getid(s));
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout << v.size();
    return 0;
}