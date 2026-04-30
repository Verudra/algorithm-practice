#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>>pq;
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++){
        int t;
        scanf("%d",&t);
        pq.push(t);
    }
    long long ans = 0;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        ans += a+b;
    }
    printf("%lld",ans);
    return 0;
}