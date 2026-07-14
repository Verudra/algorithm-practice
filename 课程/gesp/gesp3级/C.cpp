#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d; cin >> n >> d;
    vector<int>ans(n);
    for(int i = 1;i <= d;i ++){
        int t; cin >> t;
        ans[t] += i;
    }
    for(auto i : ans) cout << i << ' ';
    return 0;
}