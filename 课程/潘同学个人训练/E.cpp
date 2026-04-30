#include <bits/stdc++.h>
using namespace std;
void work(){
    int n; cin >> n;
    vector<int> vec(n);
    for(auto& i : vec) cin >> i;
    auto getPre = [](vector<int> vec){
        for(int i = 1;i < vec.size();i ++) vec[i] += vec[i-1];
        return vec;
    };
    auto getSuf = [](vector<int> vec){
        for(int i = vec.size()-2;i >= 0;i --) vec[i] += vec[i+1];
        return vec;
    };
    auto getans = [](vector<int> vec, auto pre,auto suf){
        auto p = pre(vec), s = suf(vec);
        for(int i = 0;i < vec.size()-1;i ++) if(p[i] == s[i+1]) return true;
        return false;
    };
    if(getans(vec,getPre,getSuf)) printf("Yes\n");
    else printf("No\n");
    return ;
}
int main(){
    int t; cin >> t;
    while(t --) work();
    return 0;
}