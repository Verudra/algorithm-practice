#include <bits/stdc++.h>
using namespace std;
int main(){
    /*
        n: 序列长度
        vec: 读入的序列
        ans: 历史最大子段和
        now: 包含当前元素的最大子段和
    */
    const int INF = 0x7f7f7f7f;
    int n;
    int ans = -INF, now = 0;
    // 读入数据
    scanf("%d",&n);
    vector<int> vec(n+1);
    for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);

    // 遍历一次，直接得出答案
    for(int i = 1;i <= n;i ++){
        if(now < 0) now = vec[i]; // 小于零前面的就可以不要了
        else now += vec[i]; // 大于零可以把前面接到vec[i]的前面
        ans = max(ans, now);
    }

    // 输出答案
    printf("%d", ans);
    return 0;
}