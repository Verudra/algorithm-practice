#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    for(int i = 1;i <= 100;i ++){
        for(int j = 1;j <= 50;j ++){
            for(int k = 1;k <= 20;k ++){
                if(i+j*2+k*5 == 100) cnt ++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}