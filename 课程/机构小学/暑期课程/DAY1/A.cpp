#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int cnt[N];
int main(){
    int n; cin >> n;
    int maxn = 0;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        if(maxn < t) maxn = t;
        cnt[t] ++;
    }
    for(int i = 0;i <= maxn;i ++){
        cout << cnt[i] << '\n';
    }
    return 0;
}