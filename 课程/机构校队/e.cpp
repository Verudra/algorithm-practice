#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int sa[N];
int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        int t; cin >>  t;
        if(!(t&1)) sa[++cnt] = t;
    }
    sort(sa+1,sa+1+n,[](int a,int b){return a > b;});
    for(int i = 1;i <= cnt;i ++) cout << sa[i] << ' ';
    return 0;
}