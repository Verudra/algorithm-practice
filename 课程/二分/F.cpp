#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>v(n);
    int s = 0, maxn = -INF;
    for(auto& i : v) scanf("%d",&i),s += i,maxn = max(maxn,i);
    int l = maxn,r = s;
    auto pd = [&](int mid){
        int res = 1;
        int now = 0;
        for(auto i : v){
            if(i + now > mid) res ++,now = i;
            else now += i; 
        }
        if(res > m) return false;
        return true;
    };
    while(l < r){
        int mid = l+r>>1;
        if(pd(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d",l);
    return 0;
}