#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N];
int dp[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j < i;j ++){
            dp[i] = 1;
            if(sa[i] < sa[j]) dp[i] = max()
        }
    }
}