#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    if (n <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }

    // 1. 从小到大排序
    sort(t.begin(), t.end());

    int total_time = 0;
    int curr = n - 1; // 指向当前最慢的人的索引

    // 2. 贪心处理，每次送走最慢的两个人
    while (curr >= 3)
    {
        // 方案 1: t[0] 两次带人
        int opt1 = t[curr] + t[0] + t[curr - 1] + t[0];
        // 方案 2: t[0], t[1] 配合，让最慢的两个一起走
        int opt2 = t[1] + t[0] + t[curr] + t[1];

        total_time += min(opt1, opt2);
        curr -= 2; // 送走了两个最慢的
    }

    // 3. 处理剩余的 1, 2, 3 个人
    if (curr == 2)
    {
        // 剩 3 个人 (t0, t1, t2): t0 带 t2 过去，t0 回，t0 带 t1 过去
        total_time += t[2] + t[0] + t[1];
    }
    else if (curr == 1)
    {
        // 剩 2 个人 (t0, t1): 直接一起过去
        total_time += t[1];
    }
    else if (curr == 0)
    {
        // 剩 1 个人 (t0): 直接过去
        total_time += t[0];
    }

    cout << total_time << endl;

    return 0;
}