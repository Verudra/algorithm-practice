#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n;
        scanf("%d",&n);
        int t, ans = -1;
        for(int i = 1;i <= n;i ++){
            scanf("%d",&t);
            ans = max(ans,t);
        }
        printf("%d\n",ans);
    }
    return 0;
}