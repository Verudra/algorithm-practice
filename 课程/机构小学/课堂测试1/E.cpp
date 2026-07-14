#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
char sa[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    for(char c = 'a';c <= 'z';c ++){
        bool flag = false;
        for(int i = 1;i <= n;i ++){
            if(sa[i] == c){
                flag = true;
                break;
            }
        }
        if(!flag) cout << c << ' ';
    }
    return 0;
}