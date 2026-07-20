#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int> >pa(s1.size()+1, vector<int>(s2.size()+1));
    For(i,1,s1.size()){
        For(j,1,s2.size()){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int x = s1.size(), y = s2.size();
    stack<char>ans;
    while(x >= 1 && y >= 1){
        if(dp[x][y] == dp[x-1][y-1]+1) ans.push(s1[x-1]), x--, y--;
        else if(dp[x][y] == dp[x-1][y]) x--;
        else y--;
    }
    while(ans.size()){
        cout << ans.top();
        ans.pop();
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}