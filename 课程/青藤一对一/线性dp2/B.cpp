#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int> >dp(s1.size()+1, vector<int>(s2.size()+1));
    dp[0][0] = 0;
    For(i, 1, s1.size()) dp[i][0] = i;
    For(i, 1, s2.size()) dp[0][i] = i;
    For(i, 1, s1.size()){
        For(j, 1, s2.size()){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
        }
    }
    cout << dp[s1.size()][s2.size()];
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}