#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq1;                            // 大根堆
    priority_queue<int, vector<int>, greater<int>> pq2; // 小根堆
    int val = 1;
    pq2.push(val);       // 向堆中放置数字val
    int now = pq2.top(); // 获取堆顶元素
    pq2.pop();           // 弹出堆顶元素
    return 0;
}
