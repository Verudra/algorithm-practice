#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++){
        double w;
        scanf("%lf",&w);
        if(w < m) printf("On Sale! %.1lf\n",w);
    }
    return 0;
}