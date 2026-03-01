#include <bits/stdc++.h>
using namespace std;
namespace Solution1{
    /* 用最合适的物品配对最贵物品 */
    void work(){
        /*
            n: 纪念品的总件数
            w: 每组纪念品价格之和的上限
            st: 未分配物品集合
            multiset可存重复数字、自升序、可修改还能二分查找，很方便（实际上一般是红黑树上查找）
        */

        // 数据读入
        int n,w;
        scanf("%d%d",&w,&n);
        multiset<int>st;
        for(int i = 1;i <= n;i ++){
            int t; scanf("%d",&t);
            st.insert(t);
        }

        // 配对过程
        int ans = 0;
        while(!st.empty()){
            /*
                now: 最便宜的未分配物品，和题解所说相反，但原理相同
                margin: 价值余量
                res: 价值严格大于余量的第一个物品，往前查一个就是不大于余量的最贵物品
            */
            auto now = *st.begin(), margin = w-now;
            st.erase(st.begin()); ans ++;
            auto res = st.upper_bound(margin);
            if(res != st.begin()) //这里注意判断，可能不存在能和最贵配对的物品
                st.erase(--res);
        }

        // 输出答案
        printf("%d",ans);
    }
}
namespace Solution2{
    /* 直接最大最小拼一起判断 */
    void work(){
        /*
            n: 纪念品的总件数
            w: 每组纪念品价格之和的上限
            vec: 存纪念品价值的数组
            l: 左指针，指向最便宜物品
            r: 右指针，指向最贵物品
        */
        int w, n;
        int l = 1, r = n, ans = 0;

        // 数据读入
        scanf("%d%d",&w,&n);
        vector<int>vec(n+1);
        for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]);

        // 排序，为双指针处理做铺垫
        sort(vec.begin()+1,vec.end());

        // 双指针处理过程
        while(l <= r){
            if(l == r){
                ans ++;
                break;
            }
            if(vec[l]+vec[r] > w) r --, ans ++;
            else l ++, r --, ans ++;
        }

        // 答案输出
        printf("%d",ans);
        return ;
    }
}
int main(){
    // Solution1::work();
    Solution2::work();
    return 0;
}