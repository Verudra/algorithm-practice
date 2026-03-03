#include <bits/stdc++.h>
using namespace std;
void work()
{
    /*
        n: 排列长度
        x: 第一个传送门的位置
        y: 第二个传送门的位置
        INF: int的无穷大
        vec: 读入的排列
        veca: x左y右的部分
        vecb: x有y左的部分
        minval_b: vecb中的最小值
        minpos_b: vecb中最小值的位置
        flag: 判断是否输出过vecb部分
    */
    int n, x, y;
    const int INF = 0x7f7f7f7f;
    int minval_b = INF, minpos_b = 0;
    bool flag = false;

    // 读入
    scanf("%d%d%d", &n, &x, &y);
    vector<int> vec(n + 1), veca, vecb;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &vec[i]);
    }

    // 拆分为两个部分
    for (int i = 1; i <= n; i++)
    {
        if (i <= x || i > y)
            veca.push_back(vec[i]);
        else
        {
            vecb.push_back(vec[i]);
            if (minval_b > vec[i])
            { // 记录一下最小值及其位置
                minval_b = vec[i];
                minpos_b = vecb.size() - 1;
            }
        }
    }

    // 遍历a部分，看时机输出b部分
    for (int i = 0; i < veca.size(); i++)
    {
        if (flag == false && veca[i] > minval_b)
        {                // b部分没输出过，并且当前的a值大于b部分最小值
            flag = true; // 标记输出过了
            for (int j = 0; j < vecb.size(); j++)
            {
                printf("%d ", vecb[(j + minpos_b) % vecb.size()]);
            }
        }
        printf("%d ", veca[i]);
    }
    if (flag == false)
    { // 如果没输出过b部分，在最后输出一下
        for (int j = 0; j < vecb.size(); j++)
        {
            printf("%d ", vecb[(j + minpos_b) % vecb.size()]);
        }
    }
    printf("\n");
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