#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x7f7f7f7f7f7f7f7f;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>a(n),b(n);
    ll sumb = 0;
    for(auto& i : a) scanf("%d",&i);
    for(auto& i : b) scanf("%d",&i), sumb += i;
    ll ans = -INF;
    for(int k = 0;k <= 1e6;k ++){
        ll tmp = 0;
        unordered_map<int,ll>scor;
        for(int i = 0;i < n;i ++){
            if(i*k > 1e6) break;
            int t = a[i]-i*k;
            if(t >= 0){
                scor[t] += b[i];
                tmp = max(tmp,scor[t]);
            }
        }
        ans = max(ans, tmp);
    }
    printf("%lld",sumb-ans);
    return 0;
}