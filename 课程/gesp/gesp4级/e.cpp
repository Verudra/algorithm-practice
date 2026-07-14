#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string BD = "!()-[]{}\\|;:'\",./?<>";

bool ck(char c){
    for(auto i:BD) if(c == i) return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        string s1,s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    string s; cin >> s; s += '.';
    string ts = "";
    for(int i = 0;i < s.length();i ++){
        if(!ck(s[i])) ts += s[i];
        else{
            if(mp.count(ts)) cout << mp[ts];
            else cout << "UNK";
            ts = "";
            if(i != s.length()-1) cout << s[i];
        }
    }
    return 0;
}