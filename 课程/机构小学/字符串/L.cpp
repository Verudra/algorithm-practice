#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    string s; getline(cin,s);
    string ts, mxs, mis(105,'a');
    s += ' ';
    For(i,0,s.size()-1){
        if(s[i] == ' ' || s[i] == ','){
            if(ts.empty()) continue;
            if(mxs.size() < ts.size()) mxs = ts;
            if(mis.size() > ts.size()) mis = ts;
            ts = "";
        }
        else ts += s[i];
    }
    cout << mxs << '\n' << mis;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}