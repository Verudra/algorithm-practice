#include <bits/stdc++.h>
using namespace std;
void work(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>dif(n+2),ans(n+1,-1);
    vector<bool>flagL(n+1,false),flagR(n+1,false);
    for(int i = 1;i <= m;i ++){
        int l,r;
        scanf("%d%d",&l,&r);
        dif[l] ++; dif[r+1] --;
        flagL[l] = true; flagR[r] = true;
    }
    for(int i = 1;i <= n;i ++){
        dif[i] = dif[i-1] + dif[i];
    }
    int pos = -1;
    for(int i = 1;i <= n;i ++){
        if(dif[i] == m){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        ans[pos] = 0;
        int cnt = 1;
        for(int i = 1;i <= n;i ++){
            if(ans[i] == -1) ans[i] = cnt ++;
        }
        for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
        printf("\n");
    }
    else{
        bool flag = false;
        for(int i = 1;i < n;i ++){
            if(!flagL[i+1]){
                ans[i] = 1;
                ans[i+1] = 0;
                flag = true;
                break;
            }
            if(!flagR[i]){
                ans[i] = 0;
                ans[i+1] = 1;
                flag = true;
                break;
            }
        }
        int cnt = 2;
        if(flag){
            for(int i = 1;i <= n;i ++){
                if(ans[i] == -1) ans[i] = cnt ++;
            }
            for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
            printf("\n");
        }
        else{
            for(int i = 1;i <= n;i ++){
                if(i == 1) ans[i] = 0;
                else if(i == 2) ans[i] = 2;
                else if(i == 3) ans[i] = 1;
                else ans[i] = i-1;
            }
            for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return ;
}
int main(){
    // freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}