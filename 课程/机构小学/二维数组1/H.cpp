#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    int s = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            int t; cin >> t;
            if(j <= n-i) s += t;
        }
    }
    cout << s;
    return 0;
}