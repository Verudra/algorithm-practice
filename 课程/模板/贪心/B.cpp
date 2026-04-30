#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    // 读取果子种类数
    if (!(cin >> n))
        return 0;

    // 定义一个小根堆 (priority_queue 默认是大根堆，所以需要加上 greater<int>)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        int weight;
        cin >> weight;
        pq.push(weight); // 将每堆果子的重量放入优先队列
    }

    long long total_energy = 0; // 累计消耗的体力

    // 当队列中不止一堆果子时，继续合并
    while (pq.size() > 1)
    {
        // 取出当前最小的两堆
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        // 合并这两堆，计算体力消耗
        int combined = first + second;
        total_energy += combined;

        // 将合并后的新堆放入队列
        pq.push(combined);
    }

    // 输出最终结果
    cout << total_energy << endl;

    return 0;
}