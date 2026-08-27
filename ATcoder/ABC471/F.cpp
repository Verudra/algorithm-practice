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
#define len(s) ((int)s.size())
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
struct node{
    string s; int val;
};
bool cmp_key(const node& a,const node& b){
    if(len(a.s) != len(b.s)) return len(a.s) > len(b.s);
    return a.val > b.val; 
}
bool cmp_cont(const string& s1,const string& s2){
    return s1+s2 > s2+s1;
}
string contact(vector<string>v){
    sort(v.begin(),v.end(),cmp_cont);
    string res;
    for(auto s : v) res += s;
    int p = 0;
    while(p+1<len(res) && res[p]=='0') p ++;
    return res.substr(p);
}
bool large(string a,string b){
    if(len(a)>len(b) || len(a)==len(b)&&a>b) return true;
    return false;
}
void work(){
    int n,k; cin >> n >> k;
    vector<node>v(n);
    rep(i,n){
        cin >> v[i].s;
        v[i].val = stoll(v[i].s);
    }
    sort(v.begin(),v.end(),cmp_key);
    vector<string> v1,v2;
    int pos = n-1;
    For(i,k,n-1) if(v[i].val > v[pos].val) pos = i;
    rep(i,k-1) v1.push_back(v[i].s);
    rep(i,k) v2.push_back(v[i].s);
    v1.push_back(v[pos].s);
    string ans1 = contact(v1), ans2 = contact(v2);
    cout << (large(ans1,ans2)?ans1:ans2);
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