#include <bits/stdc++.h>
using namespace std;
int getnum(string s){
    int res = 0;
    for(auto i : s){
        res = res*10+i-'0';    
    }
    return res;
}
int getsiz(string s){
    if(s == "km") return 1;
    if(s == "m") return 1000;
    return 1000000;
}
void work(){
    string s1,s2,s3,s4,s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << getnum(s1)*getsiz(s5)/getsiz(s2) << ' ' << s5 << '\n';
    return ;
}
int main(){
    int n; cin >> n;
    while(n --){
        work();
    }
    return 0;
}