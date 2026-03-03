#include <bits/stdc++.h>
using namespace std;
void work(){
    /*
        n: 数组长度
        flag: 标记存在一个数有多个质因子，或分解成质因子的最终序列不是非递减的
        flag1: 标记最开始的数组是否是非递减的
        la: 记录读入初始数组过程的上一个数字是几
        vec: 所有数字分解成质因子后组成的数组
    */
    int n;
    bool flag = false;
    bool flag1 = false;
    int la = 0;

    // 读入
    scanf("%d",&n);
    vector<int>vec,vec1(n+1);
    for(int i = 1;i <= n;i ++){ // 读入时顺便判断一下是否是非递减的
        scanf("%d",&vec1[i]);
        if(vec1[i] < la) flag1 = true;
        else la = vec1[i];
    }
    if(flag1 == false){ // 一打开始就是非递减的，直接Bob获胜
        printf("Bob\n");
        return ;
    }
    for(int i = 1;i <= n;i ++){ // 依次判断每个数字，判断是否存在数字有至少两个质因子
        int t = vec1[i];
        int cnt = 0; // 记录质因子的个数
        for(int j = 2;j*j <= t;j ++){
            if(t%j == 0){
                vec.push_back(j); // 将分解出的质因子放到vec中
                cnt ++; // 质因子个数加一
                while(t%j == 0) // 把当前因子除完
                    t /= j;
            }
        }
        if(t != 1){ // 如果最后不是1，说明还有一个质因子
            vec.push_back(t);
            cnt ++;
        }
        if(cnt > 1) flag = true;  // 质因子个数大于1个
        if(cnt == 0) vec.push_back(1); // 说明这个数字本来就是1,也得特判一下，加入vec中
    }
    for(int i = 1;i < int(vec.size());i ++){ // 判断最后的vec是否是非递减的
        if(vec[i] < vec[i-1]) flag = true;
    }
    if(flag == true) printf("Alice\n");
    else printf("Bob\n");

}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}