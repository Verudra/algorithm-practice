#include <bits/stdc++.h>
using namespace std;
const int N = 255;
int cnt[N];
int main(){
    int n; cin >> n;
    char maxc;
    int maxcnt = 0;
    for(int i = 1;i <= n;i ++){
        char c; cin >> c;
        cnt[c] ++;
        if(cnt[c] > maxcnt){
            maxcnt = cnt[c];
            maxc = c;
        }
    }
    cout << maxc << ' ' << maxcnt;
    return 0;
}