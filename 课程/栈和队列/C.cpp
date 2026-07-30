#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    while(m --){
        string ss; cin >> ss;
        stack<char>stk1;
        int p = 0;
        for(int i = 0;i < n;i ++){
            stk1.push(s[i]);
            while(!stk1.empty() && stk1.top()==ss[p])
            {//一个个入栈，如果和出栈p位置字母相同则弹出并后移p 
                stk1.pop();
                p ++;
            }
        }
        if(p == n) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}