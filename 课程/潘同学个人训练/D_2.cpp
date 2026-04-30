#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    string s;
    cin >> s;
    bool f1,f2,f3,f4;
    f1 = f2 = f3 = f4 = true;
    for(int i = 0;i < s.size();i ++){
        if(s[i] >= '2') f1 = false;
        if(s[i] >= '8') f2 = false;
        if(s[i] >= 'A' && s[i] <= 'F') f3 = false;
        if(s[i] > 'F') f4 = false;
    }
    
    //cout << 
    return 0;
} 