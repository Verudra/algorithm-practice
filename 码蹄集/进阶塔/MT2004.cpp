#include <bits/stdc++.h>
using namespace std;
string getans(string s){
    int pos0 = 0; while(s[pos0]=='0' && pos0 < s.size()) pos0 ++;
    if(pos0 == s.size()) return "0";
    s = s.substr(pos0);
    if(s.size() == 1) return s;
    string Ls = s.substr(0, s.size()+1>>1);
    auto getDS = [&](string Ls){
        string Rs = Ls;
        if((s.size())&1) Rs.pop_back();
        reverse(Rs.begin(),Rs.end());
        return Ls+Rs;
    };
    string S = getDS(Ls);
    if(S <= s) return S;
    for(int i = Ls.size()-1;i >= 0;i --){
        if(Ls[i]!='0'){
            Ls[i] --;
            break;
        }
        else Ls[i] = '9';
    }
    if(Ls[0] == '0') return string(s.size()-1,'9');
    return getDS(Ls);
}
int main(){
    string s;
    cin >> s;
    cout << getans(s);
    return 0;
}