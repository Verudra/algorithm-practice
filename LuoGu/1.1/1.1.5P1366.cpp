#include<bits/stdc++.h>
using namespace std;
namespace Solution1{
    /* 双指针求解 */
    /*
        N: 数组大小
        sa[]: 存储A数组
        sb[]: 存储B数组
        n: A数组大小
        m: B数组大小
        l: 左指针(A数组的指针)
        r: 右指针(B数组的指针)
        ans: 存储答案
        br: 第一次判定相等时B数组位置
        flag: 判断是否是第一次相等
    */
   
    typedef unsigned long long ull;// 注意 2^64数据范围，要用ull
    const int N = 1e7+10;
    ull sa[N], sb[N];
    int n, m;
    int l = 1, r = 1, ans = 0;
    int br; bool flag;

    void work(){
        // 读入数据
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i ++) scanf("%llu",&sa[i]);
        for(int i = 1;i <= m;i ++) scanf("%llu",&sb[i]);

        // 双指针求解
        while(l <= n){
            br = r; flag = false;
            while(r <= m && sb[r] <= sa[l]){
                if(sb[r] == sa[l] && flag == false){
                    flag = true;
                    br = r;
                }
                r ++;
            }
            if(flag) ans ^= r-br;
            l ++;
        }

        // 答案输出
        printf("%d\n",ans);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        Solution1::work();
    }
    return 0;
}