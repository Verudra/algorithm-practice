#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int sa[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sa[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i + 1; j--)
        { // 注意这里要从后到前遍历
            if (sa[j] < sa[j - 1])
            { // 注意这里我是和前一个比较
                swap(sa[j], sa[j - 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", sa[i]);
    }
    return 0;
}