#include <bits/stdc++.h>
using namespace std;
const int N = 2e7+10;
bool vis[N];
int nxt[N];
void init(int n){
    auto pd = [](int x){
        while(x){
            if(x%10==7) return true;
            x /= 10;
        }
        return false;
    };
    for(int i = 7;i < n;i ++){
        if(pd(i)){
            vis[i] = true;
            for(int j = i;j <= n;j += i) vis[j] = true;
        }
    }
    int la = -1;
    for(int j = n;j >= 1;j --){
        nxt[j] = la;
        if(vis[j] == false) la = j;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1.1e7);
    int T; cin >> T;
    while(T --){
        int t; cin >> t;
        if(vis[t] == true) cout << "-1\n"; else cout << nxt[t] << '\n';
    }
    return 0;
}