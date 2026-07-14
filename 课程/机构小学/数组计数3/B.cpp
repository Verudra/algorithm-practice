#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int cnt[N];
int main(){
    int n; cin >> n;
    int maxval = -1;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        cnt[t] ++;
        if(t > maxval) maxval = t;
    }
    for(int i = 0;i <= maxval;i ++){
        cout << cnt[i] << '\n';
    }
    return 0;
}