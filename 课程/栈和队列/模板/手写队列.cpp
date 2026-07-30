#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int que[N], tail=-1, head=0; // 注意初始化头尾指针位置
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t;
        cin >> t;
        que[++ tail] = t; // 往队列尾放元素
    }
    while(head <= tail){ // 判断队列是否为空
        cout << que[head ++] << ' '; // 输出队首元素，同时弹出队首
    }
    return 0;
}