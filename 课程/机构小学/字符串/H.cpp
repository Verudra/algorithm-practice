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
    string s1,s2;
    getline(cin,s1); getline(cin,s2);
    string s11, s22;
    For(i,0,s1.size()){
        if(s1[i] == ' ') continue;
        s11 += toupper(s1[i]);
    }
    For(i,0,s2.size()){
        if(s2[i] == ' ') continue;
        s22 += toupper(s2[i]);
    }
    if(s11 == s22) cout << "YES";
    else cout << "NO";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}