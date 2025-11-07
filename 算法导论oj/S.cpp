#include <bits/stdc++.h>
using namespace std;
string getUP(string s){
    for(int i = 0;i < s.length();i ++){
        if(s[i] >= 'a' && s[i] <= 'z') s[i] += 'A'-'a';
    }
    return s;
}
bool isUP(char c){
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}
char cToLow(char c){
    if(isUP(c)) return c+('a'-'A');
    return c;
}
const int N = 1005;
bool vis[N];
int main(){
    string skey,sout;
    cin >> skey >> sout;
    for(int i = 0;i < sout.length();i ++){
        if(isUP(sout[i])) vis[i] = true;
    }
    skey = getUP(skey);
    sout = getUP(sout);
    // cout << skey << '\n' << sout << '\n' << "END!" << '\n';
    for(int i = 0;i < sout.length();i ++){
        sout[i] = 'A' + ((sout[i]-'A')-(skey[i%skey.length()]-'A')+'Z'-'A'+1)%('Z'-'A'+1);
    }
    // cout << sout << '\n' << "UPstring is UPModle\n";
    for(int i = 0;i < sout.length();i ++){
        if(vis[i]) cout << sout[i];
        else cout << cToLow(sout[i]);
    }
    return 0;
}