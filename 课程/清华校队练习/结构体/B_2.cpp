#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int nums[N];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> nums[i];
    }
    sort(nums+1,nums+1+n,greater<int>()); // sort默认从小到大排序，注意排序范围左闭右开
    for(int i = 1;i <= n;i ++){
        cout << nums[i] << ' '; 
    }
    return 0;
}