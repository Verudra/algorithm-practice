#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int cnt[1005];
int pos = 0,sa[1005];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        if(!cnt[t]) sa[++pos] = t;
        cnt[t] ++;
    }
    sort(sa+1,sa+1+pos);
    cout << pos << '\n';
    for(int i = 1;i <= pos;i ++) cout << sa[i] << ' ';
    return 0;
}