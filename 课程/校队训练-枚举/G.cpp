#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 0;i <= 50;i ++){
        for(int j = 0;j <= 50;j ++){
            if(i+j == 50 && i*2+j*4 == 160) printf("%d %d\n",i,j);
        }
    }
    return 0;
}