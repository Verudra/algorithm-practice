#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int cnt[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        cnt[t] ++;
    }
    for(int i = 1;i <= 1000;i ++){
        if(cnt[i]%2 == 1) cout << i;
    }
    return 0;
}