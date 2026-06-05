#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
const int N = 10005;
int a1,a2,b1,b2,b3;
struct node{
    int day,op1,op2,op3;
    int pd;
}sa[N];
int tot;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d%d",&a1,&a2,&b1,&b2,&b3);
    for(int i = 1;i <= n;i ++){
        int d,op;
        scanf("%d%d",&d,&op);
        if(mp.count(d) == 0){
            sa[++tot].day = d;
            mp[d] = tot;
            node& now = sa[tot];
            if(op == 1) now.op1 ++;
            else if(op == 2) now.op2 ++;
            else if(op == 3) now.op3 ++;
        }
        else{
            node& now = sa[mp[d]];
            if(op == 1) now.op1 ++;
            else if(op == 2) now.op2 ++;
            else if(op == 3) now.op3 ++;
        }
    }
    for(int i = 1;i <= m;i ++){
        int t,op;
        scanf("%d%d",&t,&op);
        sa[mp[t]].pd = op;
    }
    int ans1 = 0,ans2 = 0;
    for(int i = 1;i <= tot;i ++){
        auto now = sa[i];
        int aa1 = a1, aa2 = a2,bb1 = b1,bb2 = b2,bb3 = b3;
        if(now.pd == 1) ans2 -= now.op1*bb1/2;
        else ans2 -= now.op1*bb1;
        if(now.pd == 2) ans2 -= now.op2*bb2/2;
        else ans2 -= now.op2*bb2;
        if(now.pd == 3) ans2 -= now.op3*bb3/2;
        else ans2 -= now.op3*bb3;
        ans1 += now.op1*aa1 - now.op3*aa2;
        // ans2 -= now.op1*bb1 + now.op2*bb2 + now.op3*bb3; 
    }
    printf("%d %d",ans1,ans2);
    return 0;
}