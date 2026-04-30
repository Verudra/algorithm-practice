#include<bits/stdc++.h>
using namespace std;
int main(){
    int x = 2025;
    int cnt = 1;

    auto fun = [](int x_)->int {
        int res = 5+(x_&1?15:2);
        switch(x_%3){
            case 1: res += 2; break;
            case 2: res += 10; break;
            case 0: res += 7; break;
        }
        return res;
    };

    while(cnt){
        x -= fun(cnt);
        if(x <= 0){
            printf("%d",cnt);
            break;
        }
        cnt ++;
    }

    return 0;
}