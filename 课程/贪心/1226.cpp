#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> vec(n);
    for(auto& i : vec) scanf("%d%d",&i.first,&i.second);
    typedef pair<int,int> pii;
    typedef long long ll;
    sort(vec.begin(),vec.end(),[](pii a,pii b){return a.first!=b.first?a.first>b.first:a.second<b.second;});
    ll ans = 0,t = 0;
    for(auto i : vec){
        t += i.second;
        ans += i.first*t;
    }
    printf("%lld",ans);
    return 0;
}