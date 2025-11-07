#include <bits/stdc++.h>
using namespace std;
// const int N = 2005;
int main(){
    int n;
    while(cin >> n){
        string s;
        cin >> s;
        int l = 0,r = s.length()-1;
        queue<char> q;
        while(l <= r){
            bool flag = false;
            for(int i = 0;l + i <= r;i ++){
                if(s[l+i] < s[r-i]){
                    flag = true;
                    break;
                }
                if(s[l+i] > s[r-i]){
                    flag = false;
                    break;
                }
            }
            if(flag) q.push(s[l++]);
            else q.push(s[r--]);
        }
        while(!q.empty()){
            cout << q.front(); q.pop();
        }
        cout << '\n';
    }
    return 0;
}
/*
6
ACDBCB
6
ACDBCB
6
ACDBCB
*/