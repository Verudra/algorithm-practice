#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n);
    for(auto& i : vec) scanf("%d",&i);
    sort(vec.begin(),vec.end());
    int maxn = *vec.rbegin(), minn = *vec.begin();
    int maxcnt = 0, mincnt = 0;
    for(auto i : vec){
        if(i == maxn) maxcnt ++;
        if(i == minn) mincnt ++;
    }
    printf("%d %d\n%d %d",minn,mincnt,maxn,maxcnt);
    return 0;
}