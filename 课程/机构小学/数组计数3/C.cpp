#include <bits/stdc++.h>
using namespace std;
const int N = 10006;
int cnt[N];
int main(){
    int L,M;
    cin >> L >> M;
    for(int i = 1;i <= M;i ++){
        int l,r;cin >> l >> r;
        for(int j = l;j <= r;j ++){
            cnt[j] ++;
        }
    }
    int ans = 0;
    for(int i = 0;i <= L;i ++){
        if(cnt[i] == 0) ans ++;
    }
    cout << ans;
    return 0;
}