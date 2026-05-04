#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v(n+1),L(n+1),R(n+1),ans(n+1);
    for(int i = 1;i <= n;i ++) cin >> v[i];
    stack<int>st1,st2;
    for(int i = 1;i <= n;i ++){
        while(!st1.empty() && v[st1.top()] >= v[i]) st1.pop();
        L[i] = st1.empty()?0:st1.top();
        st1.push(i);
    }
    for(int i = n;i >= 1;i --){
        while(!st2.empty() && v[st2.top()] >= v[i]) st2.pop();
        R[i] = st2.empty()?n+1:st2.top();
        st2.push(i);
    }
    for(int i = 1;i <= n;i ++) ans[R[i]-L[i]-1] = max(ans[R[i]-L[i]-1],v[i]);
    for(int i = n-1;i >= 1;i --) ans[i] = max(ans[i],ans[i+1]);
    for(int i = 1;i <= n;i ++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}