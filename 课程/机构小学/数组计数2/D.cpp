#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int cnt[N];
bool ck(int x){
    memset(cnt,0,sizeof(cnt));
    int tx = x;
    while(x){
        cnt[x%10] ++;
        x /= 10;
    }
    while(tx){
        if(cnt[tx%10] != tx%10) return false;
        tx /= 10;
    }
    return true;
}
int main(){
    int l,r;
    cin >> l >> r;
    int sum = 0;
    for(int i = l;i <= r;i ++){
        if(ck(i)) sum += i;
    }
    cout << sum;
    return 0;
}