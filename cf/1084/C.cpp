#include <bits/stdc++.h>
using namespace std;
void work()
{
    /*
        n: 字符串长度
        c: 读入的单个字符
        stk: 处理栈，相同字符弹出，否则压入
    */
    int n;
    char c;
    stack<char> stk;

    scanf("%d", &n);
    getchar(); // 注意读掉换行符
    while (n--)
    {
        c = getchar();
        if (!stk.empty() && stk.top() == c) // 栈非空且和栈顶相同
            stk.pop();
        else // 否则压入
            stk.push(c);
    }
    if (stk.size() == 0) // 栈空说明所有都配对了
        printf("yes\n");
    else
        printf("no\n");
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