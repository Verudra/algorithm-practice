#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int cnt[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = i;j <= n;j += i){
            cnt[j] ++;
        }
    }
    for(int i = 1;i <= n;i ++){
        if(cnt[i]%2) cout << i << ' ';
    }
    return 0;
}