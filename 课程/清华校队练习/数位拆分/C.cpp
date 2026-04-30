#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    auto pd = [](int x)->bool {
        queue<int>q;
        stack<int>stk;
        while(x){
            q.push(x%2);
            stk.push(x%2);
            x >>= 1;
        }
        while(!q.empty() && q.front() == stk.top()){
            q.pop(); stk.pop();
        }
        if(q.empty()) return true;
        return false;
    };
    int ans = 0;
    for(int i = 1;i <= n;i ++) if(pd(i)) ans ++;
    cout << ans;
    return 0;
}