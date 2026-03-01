#include <bits/stdc++.h>
using namespace std;
namespace Solution1{
    /* 解法一：map计数法 */
    void work(){
        /*
            N: 数列长度
            C: 一个正整数，需满足 A-B = C
            mp<key:int, val:int>: 记录任一数字key出现次数val
        */

        // 读入
        int N,C;
        scanf("%d%d",&N,&C);
        vector<int>vec(N+1);
        map<int,int>mp;
        for(int i = 1;i <= N;i ++){
            scanf("%d",&vec[i]);
            //顺便记录数字出现次数
            mp[vec[i]] ++;
        }

        // 计算答案
        long long ans = 0;
        for(int i = 1;i <= N;i ++){
            ans += mp[vec[i]-C];
        }
        
        // 答案输出
        printf("%lld",ans);
        return ;
    }
}

namespace Solution2_1{
    // 解法二_优化一
    /*
        N: 数组大小上界
        struct{val:int, cnt:int}: 重复数字压到一位，cnt是val的出现次数
    */
   
    // 初始化
    const int N = 2e5+10;
    struct{
        int val, cnt;
    }sa[N];

    void work(){
        /*
            n: 数列长度
            c: 一个正整数，需满足 A-B = C
            vec: 存储数列
            R: 压缩后数组最后一个数字的位置
            lpos: 记录遍历到的当前数字第一次出现的位置
            pl: 双指针的左指针
            pr: 双指针的右指针
            ans: 记录答案的变量
        */

        int n, c, pl = 1, pr = 1;
        int R = 0, lpos = 1;
        long long ans = 0;

        // 读入数据
        scanf("%d%d",&n,&c);
        vector<int>vec(n+2); // 注意前后多留一位
        vec[n+1] = -1;// 最后一位处理边界逻辑
        for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);

        // 排序，为去重做准备
        sort(vec.begin()+1, vec.end()-1); 
        
        // 去重，压缩数组
        for(int i = 2;i <= n+1;i ++){
            if(vec[i] != vec[i-1]){
                sa[++R].val = vec[i-1];
                sa[R].cnt = i-lpos;
                lpos = i;
            }
        }

        // 双指针处理，计算答案
        while(pr <= R){
            if(sa[pr].val-sa[pl].val > c) pl ++;
            if(sa[pr].val-sa[pl].val == c) ans += 1ll*sa[pl].cnt * sa[pr].cnt, pl ++;
            if(sa[pr].val-sa[pl].val < c) pr ++;
        }

        // 输出答案
        printf("%lld", ans);
        return ;
    }
}

namespace Solution2_2{
    // 解法二_优化二
    void work(){
        /*
            n: 数列长度
            c: 一个正整数，需满足 A-B = C
            vec: 存储数列
            r1: 右区间的左端点
            r2: 右区间的右端点
            ans: 统计答案
        */

        int n,c;
        int r1 = 1, r2 = 1;
        long long ans = 0;

        // 读入数据
        scanf("%d%d",&n,&c);
        vector<int>vec(n+1);
        for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);

        // 排序，为双指针做准备
        sort(vec.begin()+1,vec.end());
        for(int l = 1;l <= n;l ++){
            while(vec[r1]-vec[l] < c && r1 <= n) r1 ++;
            while(vec[r2]-vec[l] <= c && r2 <= n) r2 ++;
            ans += r2-r1;
        }

        // 输出答案
        printf("%lld",ans);
        return ;
    }
}

namespace Solution2_3{
    // 解法二_优化三
    void work(){
        /*
            n: 数列长度
            c: 一个正整数，需满足 A-B = C
            vec: 存储数列
            pl: 指向左区间最后一位的指针，双指针中的左指针
            pr: 指向右区间最后一位的指针，双指针中的右指针
            cntl: 记录左区间长度
            cntr: 记录右区间长度
            ans: 记录答案
        */

        int n,c;
        int pl = 1, pr = 1;
        int cntl, cntr;
        long long ans = 0;

        // 读入数据
        scanf("%d%d",&n,&c);
        vector<int>vec(n+1);
        for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);

        // 排序，双指针要用
        sort(vec.begin()+1,vec.end());
        while(pr <= n){
            if(vec[pr]-vec[pl] > c) pl ++;
            if(vec[pr]-vec[pl] == c){
                cntl = 0, cntr = 0;
                while(vec[pl] == vec[pl+1]) cntl ++, pl ++;
                cntl ++, pl ++;
                while(vec[pr] == vec[pr+1]) cntr ++, pr ++;
                cntr ++, pr ++;
                ans += 1ll*cntl*cntr;// 注意cntl*cntr会超longlong
            }
            if(vec[pr]-vec[pl] < c) pr ++;
        }

        // 输出答案
        printf("%lld",ans);
        return ;
    }
}

int main(){
    // Solution1::work();
    // Solution2_1::work();
    Solution2_3::work();
    return 0;
}