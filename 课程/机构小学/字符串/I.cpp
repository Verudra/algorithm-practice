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
    cin >> s1 >> s2;
    if(s1.size() < s2.size()) swap(s1,s2);
    s1 = s1 + s1;
    bool ans = false;
    For(i, 0, s1.size()-s2.size()){
        bool f = true;
        For(j, 0, s2.size()-1){
            if(s1[i+j] != s2[j]){
                f = false;
                break;
            }
        }
        if(f){ans = true; break;}
    }
    if(ans) cout << "true";
    else cout << "false";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}