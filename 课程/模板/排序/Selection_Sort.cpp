#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int sa[N];
const int INF = 0x7f7f7f7f;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &sa[i]);
    for (int i = 1; i <= n; i++)
    {
        int minn = INF, minpos = -1;
        for (int j = i; j <= n; j++)
        { // 选出待排序数字中的最小值
            if (minn > sa[j])
            {
                minn = sa[j];
                minpos = j;
            }
        }
        swap(sa[minpos], sa[i]); // 交换到第一位
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", sa[i]);
    return 0;
}