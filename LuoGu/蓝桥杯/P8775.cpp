#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int>vec(n+1),pre(n+1);
    for(int i = 1;i < n;i ++) scanf("%d",&vec[i]);
    for(int i = 1;i <= n;i ++) pre[i] = pre[i-1] + vec[i];
    int L = 1,R = n;
    auto check = [&](int mid){
        for(int i = 1;i <= n-mid;i ++){
            if(pre[i+mid-1]-pre[i-1] < x*2) return false;
        }
        return true;
    };
    while(L < R){
        int mid = (L+R)>>1;
        if(check(mid)) R = mid;
        else L = mid+1;
    }
    printf("%d",L);
    return 0;
}