#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<int>v(n);
    for(auto& i : v) cin >> i;
    vector<int>pre(n),suf(n);
    stack<int>stk;
    for(int i = 0;i < n;i ++){
        while(!stk.empty()&&v[stk.top()]>=v[i]) stk.pop();
        if(stk.empty()) pre[i] = -1;
        else pre[i] = stk.top();
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i = n-1;i >= 0;i --){
        while(!stk.empty() && v[stk.top()]>=v[i]) stk.pop();
        if(stk.empty()) suf[i] = n;
        else suf[i] = stk.top();
        stk.push(i);
    }
    // for(int i = 0;i < n;i ++) cout << pre[i] << (i==n-1?"\n":" ");
    // for(int i = 0;i < n;i ++) cout << suf[i] << (i==n-1?"\n":" ");
    vector<int>ans(n+1);
    for(int i = 0;i < n;i ++) ans[suf[i]-pre[i]-1] = max(ans[suf[i]-pre[i]-1],v[i]);
    for(int i = n-1;i > 0;i --) ans[i] = max(ans[i],ans[i+1]);
    for(int i = 1;i <= n;i ++) cout << ans[i] << (i==n?"":" ");
    return 0;
}