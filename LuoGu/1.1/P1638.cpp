#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
        n: 有n幅画
        m: 有m位画家
        vec: vector<val:int>
            按顺序存储画的编号
        vis: vector<val:int>
            存储编号为val的画出现次数
        L: 双指针的左指针，指向当前区间的左端点
        R: 双指针的右指针，指向当前区间的右端点
        INF: int范围的无穷大
        ansL: 答案区间的左端点
        ansR: 答案区间的右端点
        minlen: 最短区间的长度
        nowcnt: 当前区间中出现了几个画家的画
    */
    int n, m;
    vector<int> vec(n + 1), vis(n + 1);
    int L = 1, R = 1; // [L,R)
    const int INF = 0x7f7f7f7f;
    int ansL = -1, ansR = -1, minlen = INF;
    int nowcnt = 0;

    // 读入
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &vec[i]);

    // 双指针处理过程
    while (R <= n)
    { // 区间代表的是 [L,R)
        while (nowcnt < m && R <= n)
        { // 只要区间还没包含完全部画家的画
            if (vis[vec[R]] == 0)
                nowcnt++; // 第一次出现这个画家的画
            vis[vec[R++]]++;
        }
        while (vis[vec[L]] > 1)
            vis[vec[L++]]--; // 只要不是某画家唯一的画
        if (nowcnt == m && minlen > R - L)
        { // 长度比最短记录还短
            minlen = R - L;
            ansL = L;
            ansR = R - 1;
        }
        vis[vec[L++]]--;
        if (vis[vec[L - 1]] == 0)
            nowcnt--;
    }
    printf("%d %d", ansL, ansR);
    return 0;
}