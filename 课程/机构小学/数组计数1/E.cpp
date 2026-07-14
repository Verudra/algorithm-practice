#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int cnt[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        if(!cnt[t]) cout << t << ' ';
        cnt[t] ++;
    }
    return 0;
}