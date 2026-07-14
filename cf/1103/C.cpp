#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
void work(){
    int a,b,x;
    cin >> a >> b >> x;
    vector<int>v1,v2;
    while(a){v1.push_back(a);a/=x;}
    while(b){v2.push_back(b);b/=x;}
    v1.push_back(0);
    v2.push_back(0);
    int ans = INF;
    for(int i = 0;i < v1.size();i ++){
        for(int j = 0;j < v2.size();j ++){
            ans = min(ans, i+j+abs(v1[i]-v2[j]));
        }
    }
    cout << ans << '\n';
    return ;
}
int main(){
    int t;cin >> t;
    while(t --){
        work();
    }
    return 0;
}