#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        v.push_back(t);
    }
    for(int i = 1;i <= m;i ++){
        next_permutation(v.begin(),v.end());
    }
    for(auto i : v) cout << i << ' ';
    return 0;
} 