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
int cnt[256];
void work(){
    int k; cin >> k;
    string s; cin >> s;
    if(k == 1){
        cout << s[0];
        return ;
    }
    int now = 1;
    if(k == 1){
        cout << s[0];
        return ;
    }
    else{
        For(i,1,s.size()-1){
            if(s[i] == s[i-1]) now ++;
            else now = 1;
            if(now == k){
                cout << s[i];
                return ;
            }
        }
    }
    cout << "No";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}