#include <bits/stdc++.h>
using namespace std;
void work(){
    /* 双指针法求解 */
    /*
        INF: int范围的无穷大
        n: 特殊单词个数
        m: 文章的单词个数
        sum: 文章包含的特殊单词（去重）个数
        ans: 记录包含最多特殊单词的最短连续段长度
        cnt: map<key:string, val:int>
            记录[L,R]内特殊单词(key)的出现次数(val)
        mp: map<key:string, val:bool>
            判断单词(key)是否是(val)特殊单词
        vec: vector<string>
            按顺序记录文章的所有单词
        l: 左指针，指向保证[1,r]范围中所有特殊单词至少出现一次的最右端位置
        r: 右指针，循环开始时指向区间右侧待扩展的第一个位置，结束时指向右移遇到的第一个特殊单词
    */
    const int INF = 0x7f7f7f7f;
    int n,m;
    int sum = 0, ans = INF;
    map<string, int>cnt;
    map<string, bool>mp;
    set<string>st;
    vector<string>vec;
    int l = 1, r = 1, now = 0;
    string s;

    // 读入数据
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> s;
        mp[s] = true; // 标记一下特殊单词
    }
    cin >> m; 
    vec.resize(m+1);
    for(int i = 1;i <= m;i ++){
        cin >> vec[i];
        if(mp[vec[i]] == true) 
            st.insert(vec[i]); // set的性质，元素是唯一的，不会重复。
    }
    sum = st.size(); 

    /* 双指针求解过程，这个过程换成for循环写会简单一些，但是不好理解 */
    while(r <= m){
        // 将r移到下一个被标记的单词处
        while(r <= m && mp[vec[r]] != true) r ++;
        if(r > m) break;
        if(cnt[vec[r]] == 0) now ++;
        cnt[vec[r]] ++; // 标记单词的出现次数加一
        while(1){
            if(mp[vec[l]] == false){// 若左指针指向非特殊单词，直接略
                l ++; 
                continue;
            }
            if(cnt[vec[l]] > 1){// 若左指针指向的特殊单词在[l,r]中出现不止一次
                cnt[vec[l]] --;
                l ++;
                continue;
            }
            break;
        }
        if(now == sum) //如果目前区间内唯一标记单词个数达到最大值
            ans = min(ans,r-l+1);
        r ++; // 注意将r指针指向新的一个开始
    }

    // 答案输出
    if(sum == 0) printf("0\n0"); // 注意判定特殊解
    else printf("%d\n%d",sum,ans);
    return ;
}
int main(){
    work();
    return 0;
}