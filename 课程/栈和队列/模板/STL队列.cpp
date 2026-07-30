#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>que; // STL的队列定义方式
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        que.push(t); // 往队尾添加元素
    }
    while(!que.empty()){ // 当队列非空时，持续循环
        cout << que.front() << ' '; // 输出队首元素
        que.pop(); // 弹出队首元素
    }
    return 0;
}