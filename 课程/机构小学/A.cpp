#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= m;j ++){
            for(int k = 1;k <= m;k ++){
                if(i*15+j*10+5*k == n && i+j+k == m){
                    printf("mu:%d gong:%d xiao:%d\n",i,j,k);
                }
            }
        }
    }
    return 0;
}