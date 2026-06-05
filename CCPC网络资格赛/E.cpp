#include<bits/stdc++.h>
using namespace std;
int work(int n,int m){
    int res = m-(n+1)/2;
    return res*2+1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",work(n,m));
    }
    return 0;
}