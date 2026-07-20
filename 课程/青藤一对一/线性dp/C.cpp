#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
int main(){
    string s1,s2; cin >> s1 >> s2;
    for(int i = 0;i < s1.size();i ++){
        for(int j = 0;j < s2.size();j ++){
            if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[s1.size()][s2.size()];
    return 0;
}