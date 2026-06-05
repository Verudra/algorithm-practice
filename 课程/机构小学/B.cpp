#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    int len = 1;
    int now = 1,sum = 0;
    for(int i = 1;i <= k;i ++){
        sum += len;
        if(now == len){
            len ++; now = 1;
        }
        else now ++;
    }
    cout << sum;
    return 0;
}