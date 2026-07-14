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
    int maxn = -1, maxcnt = 0;
    for(int i = 0;i <= 1000;i ++){
        if(cnt[i] > maxcnt){
            maxn = i;
            maxcnt = cnt[i];
        }
    }
    cout << maxn;
    return 0;
}