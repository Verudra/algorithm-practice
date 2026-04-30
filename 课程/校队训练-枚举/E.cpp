#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 0;i <= 18;i ++){
        for(int j = 0;j <= 18;j ++){
            for(int k = 0;k <= 18;k ++){
                if(i*8+j*6+k*6 == 118 && j*2+k*1 == 20 && i+j+k == 18) printf("%d %d %d\n",i,j,k);
            }
        }
    }
    return 0;
}
