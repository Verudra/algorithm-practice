#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,n,m;
    int cnt = 0;
    scanf("%d%d%d%d%d",&x,&y,&z,&n,&m);
    for(int i = 0;i <= m;i ++){
        for(int j = 0;j <= m;j ++){
            int k = m-i-j;
            if(k%z != 0 || k < 0) continue;
            if(i*x+j*y+k/z == n) cnt ++;
        }
    }
    printf("%d",cnt);
    return 0;
}