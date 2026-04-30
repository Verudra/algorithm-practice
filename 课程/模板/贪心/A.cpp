#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);  // vector是动态数组，用普通数组也一样的
    long long sum = 0; // 算牌数之和
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n; // 求平局牌数
    for (int i = 0; i < n; ++i)
    { // 思考，这个循环在干什么
        a[i] -= avg;
    }
    int moves = 0; // 求最少移动次数
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] != 0)
        { // 不等于平均数，就要移动（借或送牌给下一个牌堆）
            a[i + 1] += a[i];
            a[i] = 0;
            moves++;
        }
    }
    cout << moves << "\n";
    return 0;
}