#include <bits/stdc++.h>
using namespace std;
void work(){
    string s1,s2;
    cin >> s1 >> s2;
    int minval=0x7f7f7f7f, minpos;
    for(int i = 0;i < s2.length();i ++){
        if(minval > s2[i]){
            minpos = i; minval = s2[i];
        }
    }
    for(int i = 0;i < s1.length();i ++){
        if(minval < s1[i]){
            swap(s2[minpos],s1[i]);
            break;
        }
    }
    cout << s1 << '\n' << s2 << '\n';
    return ;
}
int main(){
    int T;
    cin >> T;
    while(T --){
        work();
    }
    return 0;
}