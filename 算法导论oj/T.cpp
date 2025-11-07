#include <bits/stdc++.h>
using namespace std;
bool isLetter(char c){
    if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') return true;
    return false;
}
bool isUpperCase(char c){
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}
bool isLowerCase(char c){
    if(c >= 'a' && c <= 'z') return true;
    return false;
}
void transUpperCase(char& c,int k){
    c = 'A' + ((c-'A') - k + ('Z'-'A'+1))%('Z'-'A'+1);
    return ;
}
void transLowerCase(char& c,int k){
    c = 'a' + ((c-'a') - k + ('z'-'a'+1))%('z'-'a'+1);
    return ;
}
int main(){
    int T;
    // scanf("%d",&T);
    cin >> T;
    while(T --){
        string s;
        cin >> s;
        int k;
        cin >> k;
        k = (k%26+26)%26;
        for(int i = 0;i < s.length();i ++){
            if(isLetter(s[i])){
                if(isUpperCase(s[i])) transUpperCase(s[i], k);
                else if(isLowerCase(s[i])) transLowerCase(s[i], k); 
            }
        }
        cout << s << '\n';
    }
    return 0;
}
/*
1
DEFGHIJKLMNOPQRSTUVWXYZa1309bcde()kkdslto
3
*/