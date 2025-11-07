#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
struct node{
    int l,r;
}sa[N];
bool cmp(const node& a,const node& b){
    if(a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++){
        scanf("%d%d",&sa[i].l,&sa[i].r);
    }
    sort(sa+1,sa+1+n,cmp);
    int maxwk = 0, maxfr = 0;
    int lent = 0;
    for(int i = 1;i < n;i ++){
        if(sa[i].r >= sa[i+1].l) lent += sa[i+1].l - sa[i].l;
        else{
            lent += sa[i].r - sa[i].l;
            maxwk = max(maxwk, lent);
            lent = 0;
            maxfr = max(maxfr, sa[i+1].l-sa[i].r);
        }
    }
    if(lent != 0){
        lent += sa[n].r - sa[n].l;
        maxwk = max(maxwk, lent);
    }
    else{
        maxwk = max(maxwk, sa[n].r - sa[n].l);
    }
    printf("%d %d\n",maxwk,maxfr);
    return 0;
}