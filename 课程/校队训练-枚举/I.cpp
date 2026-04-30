#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt = 0;
    scanf("%d",&n);
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= n/5;j ++){
            for(int k = 0;k <= n/10;k ++){
                if(i*1+j*5+k*10 == n) cnt ++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}