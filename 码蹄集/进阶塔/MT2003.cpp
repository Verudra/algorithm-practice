#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    unordered_map<ll,bool>mp;
    auto f = [](ll k){return k*(k+1)/2;};
    for(ll k = 1;k*(k+1)/2 <= n;k ++){
        mp[f(k)] = true;
    }  
    bool flag = false;
    for(ll k = 1;k*(k+1)/2 <= n;k ++){
        if(mp[n-f(k)]){
            flag = true;
            break;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}