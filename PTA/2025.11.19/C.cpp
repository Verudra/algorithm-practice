#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.length() == 6){
        for(int i = 0;i < s.length();i ++){
            printf("%c",s[i]);
            if(i == 3) printf("-");
        }
    }
    else{
        int y = (s[0]-'0')*10 + s[1]-'0';
        int d = (s[2]-'0'*10) + s[3]-'0';
        if(y < 22) printf("20");
        else printf("19");
        for(int i = 0;i < s.length();i ++){
            printf("%c",s[i]);
            if(i == 1) printf("-");
        }
    }
    return 0;
}