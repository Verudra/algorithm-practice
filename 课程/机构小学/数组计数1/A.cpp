#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int cnt[N];
int main(){
    int n, ans = -51;
    cin >> n; 
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        cnt[t+50] ++;
        if(cnt[t+50] > n/2) ans = t;
    } 
    if(ans == -51) cout << "no";
    else cout << ans;
    return 0;
}