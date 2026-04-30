#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int sa[N];
const int INF = 0x7f7f7f7f; // int范围的极大值
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sa[i]);
    }
    for (int i = 2; i <= n; i++)
    { // 从第二个数字开始插入，避免处理边界情况
        int val = sa[i], pos = 0;
        for (int j = 1; j <= i - 1; j++)
        { // 寻找合适的插入位置
            if (sa[j] < val)
                pos = j;
            else
                break;
        }
        for (int j = i; j >= pos + 2; j--)
        { // 将整体后移一位，腾出位置放val
            sa[j] = sa[j - 1];
        }
        sa[pos + 1] = val;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", sa[i]);
    }
    return 0;
}