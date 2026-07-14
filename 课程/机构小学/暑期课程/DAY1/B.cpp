#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int cnt[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t;cin >> t;
        cnt[t+50] ++;
    }
    int ans = -1;
    for(int i = 0;i <= 100;i ++){
        if(cnt[i] > n/2) ans = i;
    }
    if(ans == -1) cout << "no";
    else cout << ans-50;
    return 0;
}