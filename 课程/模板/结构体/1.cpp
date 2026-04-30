#include<bits/stdc++.h>
using namespace std;
struct node // 结构体的定义，node是自己起的结构体类型名字
{
    int id;
    double scor;
}stu[105]; 

bool cmp(node a, node b){ // 自定义比较函数
    return a.scor > b.scor;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> stu[i].id >> stu[i].scor; // 结构体变量的输入
    }
    sort(stu+1,stu+n+1,cmp); // 结构体数组的排序
    cout << stu[k].id << ' ' << stu[k].scor;
    return 0;
}