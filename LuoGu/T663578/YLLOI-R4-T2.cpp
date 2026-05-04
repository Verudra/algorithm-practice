#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    vector<int>v(n+1);
    for(int i = 1;i <= n;i ++){
        cin >> v[i];
    }
    long long ans = 0;
    for(int i = 1;i < n;i ++){
        if(t > max(v[i],v[i+1])) ans += t-max(v[i],v[i+1]);
    }
    cout << ans;
    return 0;
}