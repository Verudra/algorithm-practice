#include<bits/stdc++.h>
using namespace std;
void work(){
    /* 双指针法求解 */
    /*
        n: 表示有n头牛
        d: 奶牛能沟通的最远距离
        INF: int范围的无穷大，用来处理边界
        l: 双指针的左指针
        r: 双指针的右指针
        ans: 记录能沟通的奶牛对数
        vec: 存所有奶牛的位置
    */

    int n,d;
    const int INF = 0x7f7f7f7f;
    int l = 1, r = 1;
    long long ans = 0;

    //读入数据
    scanf("%d%d",&n,&d);
    vector<int>vec(n+2); vec[n+1] = INF;// 这里注意一下，加个边界，定义距离无穷大
    for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);

    // 位置按升序排序，为双指针算法准备单调性
    sort(vec.begin()+1,vec.end()-1);

    // 双指针处理过程
    while(l < n){
        while(vec[r]-vec[l] <= d) r ++;
        ans += r-l-1; l ++;
    }

    // 答案输出
    printf("%lld",ans);
    return ;
}
int main(){
    work();
    return 0;
}