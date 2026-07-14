#include <bits/stdc++.h>
using namespace std;
void work(){
    string s; cin >> s;
    int op = 0;
    for(int i = 0;i < s.length();i ++){
        auto ck = [](char c){return c >= 'A' && c <= 'Z';};
        int t = !ck(s[i]) ? s[i]-'0' : s[i]-'A'+10;
        if(t > 1) op |= 1<<0;
        if(t > 7) op |= 1<<1;
        if(t > 9) op |= 1<<2;
        if(t > 15) op |= 1<<3;
    }
    for(int i = 0;i < 4;i ++)
        cout << ((op&(1<<i))?'0':'1') << ' ';
    cout << '\n';
    return ;
}
int main(){
    int T; cin >> T;
    while(T --){
        work();
    }
    return 0;
}
