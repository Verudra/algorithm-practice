#include <bits/stdc++.h>
using namespace std;
const int N = 27;
int cnt[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        char c; cin >> c;
        cnt[c-'a'] ++;
    }
    for(int i = 0;i < 26;i ++){
        if(!cnt[i]) cout << char('a'+i) << ' ';
    }
    return 0;
}