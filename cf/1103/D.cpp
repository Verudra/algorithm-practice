#include <bits/stdc++.h>
using namespace std;
void work(){
    int n,k;
    cin >> n >> k;
    vector<int>v;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    bool f = false,ans = false;
    int cnt = 1;
    int la = v.front();
    for(auto i : v){
        if(!f){
            f = true;
            continue;
        }
        if(i-la <= k){
            if(i == la){
                cnt ++;
                continue;
            }
            ans = true;
            break;
        }
        if(cnt%2 == 0){
            ans = true;
            break;
        }
        cnt = 1; la = i;
    }
    if(cnt%2 == 0) ans = true;
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return ;
}
int main(){
    int t; cin >> t;
    while(t --){
        work();
    }
    return 0;
}