#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(auto& i : v) scanf("%d",&i);
    int m;scanf("%d",&m);
    while(m --){
        int t;
        int ans = INF;
        scanf("%d",&t);
        int l = 0,r = n-1;
        while(l < r){
            int mid = l+r+1>>1;
            if(v[mid] <= t) l = mid;
            else r = mid-1;
        }
        if(abs(v[l]-t) <= (l==n-1?INF:abs(v[l+1]-t))) printf("%d\n",v[l]);
        else printf("%d\n",v[l+1]);
    }
    return 0;
}