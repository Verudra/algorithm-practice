#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,p;
    scanf("%d%d%d",&m,&n,&p);
    for(int i = 0;i <= m;i ++){
        for(int j = 0;j <= m;j ++){
            for(int k = 0;k <= m;k ++){
                if(i*8+j*6+k*6 == n && j*2+k == p && i+j+k == m) printf("%d %d %d\n",i,j,k);
            }
        }
    }
    return 0;
}