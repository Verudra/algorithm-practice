#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n);
    for(auto& i : vec) scanf("%d",&i);
    int la = 0, ans = 0;
    for(auto i : vec){
        ans += i>la?i-la:0; 
        la = i;
    }
    printf("%d",ans);
    return 0;
}