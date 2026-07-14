#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int cnt[N];
int getnum(char c){
    if(c >= 'A' && c <= 'Z') return c-'A';
    return 26+c-'a';
}
int main(){
    int n;
    cin >> n;
    int pos = 0;
    char maxc; int maxcnt = 0;
    for(int i = 1;i <= n;i ++){
        char c; cin >> c;
        cnt[getnum(c)] ++;
        if(cnt[getnum(c)] > maxcnt){
            maxcnt = cnt[getnum(c)];
            maxc = c;
        }
    }
    cout << maxc << ' ' << maxcnt;
    return 0;
}