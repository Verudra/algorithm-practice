#include<bits/stdc++.h>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n; cin >> n;
    string s; cin >> s;
    auto _16to2 = [](char c){
        int t = (c>='0'&&c<='9'?c-'0':c-'A'+10);
        stack<char>stk;
        while(t){
            stk.push(t%2+'0');
            t/=2;
        }
        string res;
        For(i,1,4-(int)stk.size()) res += '0'; 
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    };
    string ans;
    for(auto c:s){
        ans += _16to2(c);
    }
    int t = 0;
    while(t < ans.size() && ans[t] == '0') t ++;
    ans = ans.substr(t);
    if(ans.empty()) cout << '0';
    else cout << ans;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}