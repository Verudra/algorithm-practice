#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int sa[N];
int main(){
    int n,r; cin >> n >> r;
    int cnt = 1;
    while(n){
        sa[cnt] = n%r;
        n /= r;
        cnt ++;
    }
    for(int i = cnt-1;i >= 1;i --){
        if(sa[i] < 9) cout << sa[i];
        else cout << char(sa[i]-10+'A');
    }
    return 0;
}