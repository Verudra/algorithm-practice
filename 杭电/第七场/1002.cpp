#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
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
    string s; cin >> s;
    int f00=0,f01=0,f10=0,f11=0;
    int cnt = 0;
    for(int i = 0;i < s.size()-1;i ++){
        if(s[i]=='0'&&s[i+1]=='0') f00 = 1;
        if(s[i]=='0'&&s[i+1]=='1') f01 = 1;
        if(s[i]=='1'&&s[i+1]=='0') f10 = 1;
        if(s[i]=='1'&&s[i+1]=='1') f11 = 1;
    }
    cnt = f00+f01+f10+f11;
    auto pd = [&](string S,string ss){
        bool res = false;
        int pos = 0;
        for(int i = 0;i < S.size();i ++){
            if(ss[pos] == S[i]) pos ++;
            if(pos == ss.size()) return true;
        }
        return false;
    };
    if(cnt <= 3) cout << cnt+1 << '\n';
    else{
        if(pd(s,"00110")||pd(s,"01100")||pd(s,"10011")||pd(s,"11001")) cout << 5 << '\n';
        else cout << 6 << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}