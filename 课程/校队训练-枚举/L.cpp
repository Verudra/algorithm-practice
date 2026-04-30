#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    scanf("%d",&k);
    int sum = 0, cnt = 1, be = 1;
    for(int i = 1;i <= k;i ++){
        sum += cnt;
        if(i-be+1 == cnt) cnt ++, be = i+1;
    }
    printf("%d",sum);
    return 0;
}