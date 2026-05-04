#include<bits/stdc++.h>
using namespace std;
const int INF = 100005;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<pair<int,int>>v(n);
    for(auto& i : v) scanf("%d%d",&i.first,&i.second);
    int l = 1,r = INF;
    auto pd = [&](int mid){
        int res = 0;
        for(auto i : v) res += (i.first/mid)*(i.second/mid);
        if(res >= k) return true;
        return false;
    }; 
    while(l < r){
        int mid = l+r+1>>1;
        if(pd(mid)) l = mid;
        else r = mid-1;
    }
    printf("%d",l);
    return 0;
}