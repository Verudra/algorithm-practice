#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int maxn = 0;
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= n;j ++){
            for(int k = 0;k <= n;k ++){
                if((i+j)%2 == 0 && (j+k)%3 == 0 && (i+j+k)%5 == 0) maxn = max(maxn,i+j+k);
            }
        }
    }
    printf("%d",maxn);
    return 0;
}