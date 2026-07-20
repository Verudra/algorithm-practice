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
int pd(char c){
    if(c >= 'A' && c <= 'Z') return 1;
    else return 2;
}
void work(){
    string s; cin >> s;
    For(i,0,s.size()-1){
        if(pd(s[i]) == 1){
            s[i] = tolower(s[i]);
            s[i] += 3;
            if(s[i] > 'z') s[i] -= 26;
        }
        else{
            s[i] = toupper(s[i]);
            s[i] += 3;
            if(s[i] > 'Z') s[i] -= 26;
        }
    }
    Rof(i,0,s.size()-1) cout << s[i];
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}