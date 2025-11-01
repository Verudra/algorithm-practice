#include <bits/stdc++.h>
using namespace std;
void work(){
    int n;
    scanf("%d",&n);
    int l = 1, r = n;
    while(l < r){
        int mid = (l+r)>>1;
        int res1, res2;
        printf("1 %d %d\n", l,mid);
        fflush(stdout);
        scanf("%d",&res1);
        printf("2 %d %d\n",l,mid);
        fflush(stdout);
        scanf("%d",&res2);
        if(res1 == res2) l = mid+1;
        else r = mid;
    }
    int ans1, ans2;
    printf("1 %d %d\n",1,n);
    printf("2 %d %d\n",1,n);
    fflush(stdout);
    scanf("%d%d",&ans1,&ans2);
    int ans = l+ans2-ans1-1;
    printf("! %d %d\n",l,ans);
    fflush(stdout);
    return ;
}
/*
1
3
1 2 3
1 3 4
*/
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}