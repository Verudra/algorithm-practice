#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int stk[N], top = -1; // top 为栈顶指针，初始化为-1
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        stk[++ top] = t; // 往栈顶放元素
    }
    while(top >= 0){ // 判断栈非空
        cout << stk[top --] << ' '; // 输出栈顶，并将栈顶弹出
    }
    return 0;
}