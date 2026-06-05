#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    sort(sa+1,sa+1+n);
    int ans = 0;
    sort(sa+1,sa+1+n,[](int a,int b){return a<b;});
    for(int i = 1;i <= n;i += 2){
        ans += sa[i+1] - sa[i];
    }
    cout << ans;
    return 0;
}