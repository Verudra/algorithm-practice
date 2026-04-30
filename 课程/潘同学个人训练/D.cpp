#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getGcd(int a, int b){
    return b==0?a:getGcd(b,a%b);
}
void work(){
    int n; cin >> n;
    vector<int>vec(n);
    map<int, bool> mp;
    for(auto&i : vec) cin >> i, mp[i] = true;
    auto getMax = [](vector<int>&vec) -> int {
        int res = -1;
        for(auto i : vec) res = max(res,i);
        return res;
    };
    auto getAllLcm = [](vector<int>&vec, auto getMax) -> int {
        ll res = *vec.begin(), maxn = getMax(vec);
        for(auto i : vec){
            res = res*i / getGcd(res,i);
            if(res > maxn) return -1;
        }
        return res;
    };
    int llcm = getAllLcm(vec, getMax);
    if(!mp[llcm]) cout << "No" << '\n';
    else cout << "Yes" << '\n';
    return ;
}
int main(){
    int t; cin >> t;
    while(t --){
        work();
    }
    return 0;
}