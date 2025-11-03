#include <bits/stdc++.h>
using namespace std;
void work(){
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    vector<int>vec;
    vec.push_back(-1);
    for(int i = 1;i <= n;i ++){
        char c = getchar();
        if(c == '0') vec.push_back(0);
        else vec.push_back(1);
    }
    int la = -k;
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        if(vec[i] == 1 && i-la >= k) ans ++;
        if(vec[i] == 1) la = i;
    }
    printf("%d\n",ans);
    return ;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}