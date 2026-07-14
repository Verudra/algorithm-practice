#include <bits/stdc++.h>
using namespace std;
void work(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    auto uni = [](string& s,int p){
        if(s[p] == '0') s[p] = '1';
        else s[p] = '0';
    };
    for(int i = 0;i+k < s.size();i ++){
        if(s[i] == '1'){
            uni(s,i);
            uni(s,i+k);
        }
    }
    if(s == string(s.size(),'0')) cout << "YES\n";
    else cout << "NO\n";
    return ;
}
int main(){
    int t; cin >> t;
    while(t --){
        work();
    }
    return 0;
}