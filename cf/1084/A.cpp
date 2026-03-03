#include <bits/stdc++.h>
using namespace std;
void work()
{
    /*
        n: 人数
        INF: int的无穷大
        maxval: 记录最多的菜数是几
        maxcnt: 记录最多菜数出现了几次
    */
    int n;
    const int INF = 0x7f7f7f7f;
    int maxval = -INF, maxcnt = 0;
    
    // 读入
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {//边读入边处理，不需要保存
        int t;
        scanf("%d", &t);
        if (t > maxval)
        {// 超过了历史最大值，更新maxval并重置maxcnt
            maxval = t;
            maxcnt = 1;
        }
        else if (t == maxval)
        {// 等于历史最大值， maxcnt++
            maxcnt++;
        }
        // 小于历史最大值没有用
    }

    // 输出
    printf("%d\n", maxcnt);
    return;
}
int main()
{
    /*T: 共有T组数据*/
    int T;
    scanf("%d", &T);
    while (T--)
    {
        work();
    }
    return 0;
}