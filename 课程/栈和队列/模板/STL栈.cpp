#include <bits/stdc++.h>
using namespace std;
stack<int>stk; // STL栈定义方法
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        stk.push(t); // 往栈顶放元素
    }
    while(!stk.empty()){ // 判断栈是否为空
        cout << stk.top() << ' '; // 访问栈顶元素（不弹出）
        stk.pop(); // 将栈顶弹出
    }
    return 0;
}