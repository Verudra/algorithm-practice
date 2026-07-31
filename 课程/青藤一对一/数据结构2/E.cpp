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
    int query_k(int k){
        int step = 1;
        while(step<<1 <= n) step <<= 1;
        int pos = 0, sum = 0;
        while(step){
            int nxt = pos+step;
            if(nxt <= n && sum + tre[nxt] < k){
                pos = nxt;
                sum += tre[nxt];
            }
            step >>= 1;
        }
        return pos+1;
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
struct node{
    int op, val;
};
int getid(const vector<int>& v,int val){
    return lower_bound(v.begin(),v.end(),val)-v.begin()+1;
}
vector<int> lsh(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

void work(){
    int n; cin >> n;
    vi v;
    vector<node> sa;
    while(n --){
        int op,val; cin >> op >> val;
        if(op == 1) v.push_back(val);
        sa.push_back({op,val});
    }
    v = lsh(v);
    bit.init(v.size());
    for(auto t : sa){
        if(t.op == 1){
            bit.add(getid(v,t.val),1);
        }
        else if(t.op == 2){
            bit.add(getid(v,t.val),-1);
        }
        else{
            cout << v[bit.query_k(t.val)-1] << '\n';
        }
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