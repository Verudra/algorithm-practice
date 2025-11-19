#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    printf("%d",max(0,n-k*m));
    return 0;
}