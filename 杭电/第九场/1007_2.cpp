#include <bits/stdc++.h>
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
const int N = 2000100;
int norm(int x,int mod){
    return (x%mod+mod)%mod;
}
struct BIT{
    int n,mod,sa[N],tre[N];
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
        val = norm(val, mod);
        sa[pos] += val;
        sa[pos] %= mod;
        while(pos <= n){
            tre[pos] += val;
            pos += lowbit(pos);
            tre[pos] %= mod;
        }
        return ;
    }
    void build(const vector<int>& v,int md){
        mod = md;
        n = v.size();
        for(int i = 1;i <= n;i ++){
            sa[i] = tre[i] = v[i-1] % mod;
        }
        for(int i = 1;i <= n;i ++){
            int j = i+lowbit(i);
            if(j <= n) tre[j] += tre[i], tre[j] %= mod;
        }
        return ;
    }
    int query(int pos){
        int res = 0;
        while(pos > 0){
            res += tre[pos];
            pos -= lowbit(pos);
            res %= mod;
        }
        return res;
    }
    int query(int l,int r){
        return norm(query(r)-query(l-1),mod);
    }
    void change(int pos,int val){
        if(pos <= 0 || pos > n) return ;
        add(pos,norm(val-sa[pos],mod));
        return ;
    }
};
BIT bit1,bit2;
int getid(const vector<int>& v,int val){
    return lower_bound(v.begin(),v.end(),val)-v.begin();
}
vector<int> lsh(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}
void work(){
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,q,k; cin >> n >> q >> k;
    vi a(n), c(n);
    vi lsha;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> c[i];
    lsha = a;
    struct node{
        int op,p,x,c,l,r;
    }; vector<node> v;
    For(i,1,q){
        int op,p,x,c,l,r; cin >> op;
        p = x = c = l = r = 0;
        if(op == 1) cin >> p >> x >> c, lsha.push_back(x);
        else cin >> l >> r;
        v.push_back({op,p,x,c,l,r});
    }
    lsha = lsh(lsha);
    int mod1 = 1e9+7, mod2 = 1e9+3;
    vi ra1(lsha.size()), ra2(lsha.size()), rc1(k), rc2(k);
    int ts1 = 0, ts2 = 0;
    rep(i,lsha.size()) ra1[i] = rng()%mod1, ra2[i] = rng()%mod2;
    int s1 = 0,s2 = 0;
    rep(i,k-1) rc1[i] = rng()%mod1, s1 = (s1+rc1[i])%mod1, rc2[i] = rng()%mod2, s2 = (s2+rc2[i])%mod2;
    rc1[rc1.size()-1] = norm(-s1,mod1); rc2[rc2.size()-1] = norm(-s2,mod2);
    auto gnum = [&](int a,int c,int op){
        int pa = getid(lsha, a), pc = c;
        int ta,tc,res;
        if(op == 1){
            ta = ra1[pa]%mod1;
            tc = rc1[pc]%mod1;
            res = ta*tc%mod1;
        }
        else{
            ta = ra2[pa]%mod2;
            tc = rc2[pc]%mod2;
            res= ta*tc%mod2;
        }
        return res;
    };
    vi sa1(n),sa2(n);
    rep(i,n) sa1[i] = gnum(a[i],c[i],1), sa2[i] = gnum(a[i],c[i],2);
    bit1.build(sa1,mod1); bit2.build(sa2,mod2);
    rep(i,q){
        auto [op,p,x,c,l,r] = v[i];
        if(op == 1){
            bit1.change(p,gnum(x,c,1));
            bit2.change(p,gnum(x,c,2));
        }
        else{
            if((r-l+1)%k != 0){
                cout << "NO\n";
                continue;
            }
            int t1 = bit1.query(l,r), t2 = bit2.query(l,r);
            if(t1 == 0 && t2 == 0) cout << "YES\n";
            else cout << "NO\n";
        }
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