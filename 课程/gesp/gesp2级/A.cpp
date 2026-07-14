#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt = 0; cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= i;j ++){
            cout << (char)('A'+ cnt++);
            cnt %= 26;
        }
        cout << '\n';
    }
    return 0;
}