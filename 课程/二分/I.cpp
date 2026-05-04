#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>v(n);
    for(auto& i : v) scanf("%d",&i);
    while(m --){
        int t; scanf("%d",&t);
        auto it = lower_bound(v.begin(),v.end(),t);
        printf("%d\n",it == v.end()?n+1:it-v.begin()+1);
    }
    return 0;
}