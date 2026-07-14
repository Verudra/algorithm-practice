#include <bits/stdc++.h>
using namespace std;
const int N = 107;
int cnt[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i < n;i ++){
        int t; cin >> t;
        cnt[t] ++;
    }
    for(int i = 1;i <= n;i ++){
        if(!cnt[i]) cout << i;
    }
    return 0;
}