#include<iostream>
#include<vector>
#include<stack>
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
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;
struct BIT{
    int n,sa[N],tre[N];
    int lowbit(int x){
        return x&-x;
    }
    void init(int _n){
        n = _n;
        for(int i = 1;i <= n;i ++){
            sa[i] = tre[i] = 0;
        }
        return ;
    }
    void add(int pos,int val){
        if(pos <= 0 || pos > n) return ;
        sa[pos] += val;
        while(pos <= n){
            tre[pos] += val;
            pos += lowbit(pos);
        }
        return ;
    }
    void build(const vector<int>& v){
        n = v.size();
        for(int i = 1;i <= n;i ++){
            sa[i] = tre[i] = v[i-1];
        }
        for(int i = 1;i <= n;i ++){
            int j = i+lowbit(i);
            if(j <= n) tre[j] += tre[i];
        }
        return ;
    }
    int query(int pos){
        int res = 0;
        while(pos > 0){
            res += tre[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    void change(int pos,int val){
        if(pos <= 0 || pos > n) return ;
        add(pos,val-sa[pos]);
        return ;
    }
};
BIT bit;
int getid(const vector<int>& v,int val){
    return lower_bound(v.begin(),v.end(),val)-v.begin()+1;
}
vector<int> lsh(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

void work(){
    int n,k; cin >> n >> k;
    vi v,v1(n+1);
    For(i,1,n){
        int t; cin >> t;
        v1[i] = t;
    }
    vi ps(n+1);
    For(i,1,n) ps[i] = ps[i-1]+v1[i];
    For(i,1,n) v.push_back(ps[i]),v.push_back(ps[i]+k);
    v.push_back(ps[0]+k);
    v = lsh(v);
    // bit.build(v);
    bit.init(v.size());
    // rep(i,v.size()) cout << v[i] << ' ';
    // cout << '\n';
    int sum = 0;
    Rof(i,0,n-1){
        bit.add(getid(v,ps[i+1]),1);
        // cout << "add:" << getid(v,ps[i]+k) << '\n' << "val:" << getid(v,ps[i]) << '\n';
        sum += bit.query(getid(v,ps[i]+k));
    }
    cout << sum;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}