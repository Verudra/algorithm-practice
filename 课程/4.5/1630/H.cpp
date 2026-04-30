#include <bits/stdc++.h>
using namespace std;
int fun(int x,int cnt){
    while(cnt --){
        x = int(sqrt(x));
        if(x == 1) break;
    }
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n);
    for(auto& i : vec) scanf("%d",&i);
    sort(vec.begin(),vec.end(),[](int a,int b){return a > b;});
    int t = 0, sum = 0;
    for(auto i : vec){
        sum += fun(i,t++);
    }
    printf("%d",sum);
    return 0;
}