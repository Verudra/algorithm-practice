#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    // cin >> n;
    scanf("%d",&n);
    vector<int>v(n);
    for(auto& i : v) scanf("%d",&i);
    int t;cin >> t;
    while(t --){
        int k;
        // cin >> k;
        scanf("%d",&k);
        int l = 0,r = n-1;
        while(l < r){
            int mid = l+r+1>>1;
            if(v[mid] <= k) l = mid;
            else r = mid-1;
        }
        // cout << (v[l]==k?l+1:-1) << '\n';
        printf("%d\n",v[l]==k?l+1:-1);
    }
    return 0;
}