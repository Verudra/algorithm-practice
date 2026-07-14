#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int cnt[N];
int main(){
    int n; cin >> n;
    int maxcnt = -1, maxval = -1;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        cnt[t] ++;
        if(cnt[t] >= maxcnt){
            if(cnt[t] == maxcnt){
                if(maxval > t) maxval = t;
            }
            else{
                maxcnt = cnt[t];
                maxval = t;
            }
        }
    }
    cout << maxval;
    return 0;
}