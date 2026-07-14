#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
void work(){
    int n; cin >> n;
    int maxn = -INF, minn = INF;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        maxn = max(maxn, t);
        minn = min(minn, t);
    }
    cout << maxn - minn + 1 << '\n';
    return ;
}
int main(){
    int t; cin >> t;
    while(t --){
        work();
    }
    return 0;
}