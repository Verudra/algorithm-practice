#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int cnt[N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int t; cin >> t;
        cnt[t] ++;
    }
    for(int i = 1;i <= n;i ++){
        if(!cnt[i]) cout << i << '\n';
    }
    return 0;
}