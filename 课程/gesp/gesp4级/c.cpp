#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getnum(char c){
    if(c >= '0' && c <= '9') return c-'0';
    else return c-'A'+10;
}
int main(){
    int M;
    cin >> M;
    while(M --){
        int K; cin >> K;
        string s; cin >> s;
        ll bs = 1, res = 0;
        for(int i = s.length()-1;i >= 0;i --){
            res += bs*getnum(s[i]);
            bs *= K;
        }
        cout << res << '\n';
    }
    return 0;
}