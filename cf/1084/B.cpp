#include <bits/stdc++.h>
using namespace std;
void work()
{
    /*
        n: 数组数字个数
        la: 记录上个读入数字的大小
        flag: 标记数组是否存在递减子段
    */
    int n;
    int la = 0;
    bool flag = false;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {// 这个可以边读入边处理，因为只和上一个元素比大小就可以判断递减
        int t;
        scanf("%d", &t);
        if (t < la)
        {// 发现递减
            flag = true;
            la = t;
        }
        else
        {// 非递减，更新下la
            la = t;
        }
    }

    // 根据flag的值分类输出答案
    if (flag == true) // 一定可以删掉其他的非递减，最后二选一删一个
        printf("1\n");
    else // 没操作空间了，直接输出数组长度
        printf("%d\n", n);
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        work();
    }
    return 0;
}