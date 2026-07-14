#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
void work(){
    int n; cin >> n;
    vector<int>v(n);
    for(auto& i : v) cin >> i;
    vector<vector<bool> >ans(n+1,vector<bool>(n+1,false));
    int tans = 0;
    for(int i = 0;i < n;i ++){
        int dic = 0; vector<int>cnt(n+1,0);
        int mi = INF, ma = -INF;
        for(int j = i;j < n;j ++){
            mi = min(mi, v[j]);
            ma = max(ma, v[j]);
            if(++cnt[v[j]] == 1) dic ++;
            if(dic == j-i+1 && ma-mi == j-i){
                ans[dic][mi] = true;
                if(mi+dic <= n) tans = max(tans,ans[dic][mi+dic]?dic:0);
                if(mi-dic >= 0) tans = max(tans,ans[dic][mi-dic]?dic:0);
            }
        }
    }
    cout << tans << '\n';
    return ;
}
int main(){
    int t; cin >> t;
    while(t --){
        work();
    }
    return 0;
}