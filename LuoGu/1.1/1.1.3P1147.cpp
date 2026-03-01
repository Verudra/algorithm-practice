#include <bits/stdc++.h>
using namespace std;
void work(){
    /* 双指针法求解 */
    /*
        M: 题目要求的正整数段的数之和
        ans: vector<pair<int,int>> 用来存答案区间左右端点
        l: 双指针的左端点
        r: 双指针的右端点
    */
    int M;
    int l = 1, r = 2;
    vector<pair<int,int> > ans;

    // 读数据
    scanf("%d",&M);

    // 双指针求解过程
    while(l < r){
        while(1ll*(l+r)*(r-l+1)/2 < M) r ++;
        if(1ll*(l+r)*(r-l+1)/2 == M) ans.push_back({l,r}), l ++;
        while(1ll*(l+r)*(r-l+1)/2 > M) l ++;
    }

    // 答案输出
    for(auto i : ans) printf("%d %d\n",i.first,i.second);
    return ;
}
int main(){
    work();
    return 0;
}