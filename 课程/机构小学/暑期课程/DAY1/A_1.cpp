#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int cnt[N];
int main(){
    int n;
    cin >> n;
    int maxn = -1;
    for(int i = 1;i <= n;i ++){
        int t;
        cin >> t;
        cnt[t] ++;
        if(t > maxn){
            maxn = t;
        }
    }
    for(int i = 0;i <= maxn;i ++){
        cout << cnt[i] << '\n';
    }
    return 0;
}