#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vec1(n),vec2(n);
    for(auto& i : vec1) scanf("%d",&i);
    for(auto& i : vec2) scanf("%d",&i);
    sort(vec1.begin(),vec1.end(),greater<int>());
    sort(vec2.begin(),vec2.end(),greater<int>());
    int l = 0,r = 0;
    int ans = 0;
    while(r < n){
        if(vec1[l] > vec2[r]){
            l ++; r ++; ans ++;
        }
        else{
            r ++;
        }
    }
    printf("%d",ans);
    return 0;
}