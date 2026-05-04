#include<bits/stdc++.h>
using namespace std;
namespace solution1{
    void solve1(){
        int n,m,k;
        cin >> n >> m >> k;
        vector<int>v(n+1);
        map<int,int>mp;
        for(int i = 1;i <= n;i ++){
            int t;cin >> t;
            v[i] = max(v[i-1],mp[t^k]);
            mp[t] = i;
        }
        for(int i = 1;i <= m;i ++){
            int l,r; cin >> l >> r;
            if(v[r] >= l) cout << "yes\n";
            else cout << "no\n";
        }
        return ;
    };
}

namespace Solution2{
    struct node{
        int l,r,id,blk;
        bool operator<(node B){
            if(blk != B.blk) return blk < B.blk;
            return blk&1 ? r < B.r : r > B.r;
        }
    };
    const int N = 1.1e6;
    int cnt[N];
    void solve(){
        int n,m,x;
        cin >> n >> m >> x;
        vector<int>v1(n+1);
        vector<node>v2(m);
        vector<string>ans(m+1);
        int blksz = sqrt(n);
        for(int i = 1;i <= n;i ++){
            cin >> v1[i];
        }
        for(int i = 0;i < m;i ++){
            cin >> v2[i].l >> v2[i].r;
            v2[i].blk = v2[i].l/blksz;
            v2[i].id = i+1;
        }
        sort(v2.begin(),v2.end());
        int l = 1,r = 0,np = 0;
        for(auto i : v2){
            while(r < i.r){
                r ++;
                np += cnt[v1[r]^x];
                cnt[v1[r]] ++;
            }
            while(l > i.l){
                l --;
                np += cnt[v1[l]^x];
                cnt[v1[l]] ++;
            }
            while(r > i.r){
                cnt[v1[r]] --;
                np -= cnt[v1[r]^x];
                r --;
            }
            while(l < i.l){
                cnt[v1[l]] --;
                np -= cnt[v1[l]^x];
                l ++;
            }
            ans[i.id] = np > 0 ? "yes\n" : "no\n";
        }
        for(int i = 1;i <= m;i ++) cout << ans[i];
        return ;
    }
}
namespace Solution3{
    const int N = 1e5+10;
    int sa[N] = {0};
    const int INF = 0x7f7f7f7f;
    struct Segment_Tree{
        int tre[N<<2] = {0};
        #define ls (u<<1)
        #define rs (u<<1|1)
        #define mid (l+r>>1)
        void build(int u,int l,int r){
            if(l == r){
                tre[u] = sa[l];
                return ;
            }
            build(ls,l,mid);
            build(rs,mid+1,r);
            tre[u] = max(tre[ls],tre[rs]);
        }
        int query(int u,int l,int r,int cl,int cr){
            if(l >= cl && r <= cr) return tre[u];
            int maxn = -INF;
            if(cl <= mid) maxn = max(maxn, query(ls,l,mid,cl,cr));
            if(cr > mid) maxn = max(maxn,query(rs,mid+1,r,cl,cr));
            return maxn;
        }
    }T;
    void solve(){
        int n,m,k;
        cin >> n >> m >> k;
        map<int,int>mp;
        for(int i = 1;i <= n;i ++){
            int t;
            cin >> t;
            sa[i] = mp[t^k];
            mp[t] = i;
        }
        T.build(1,1,n);
        for(int i = 1;i <= m;i ++){
            int l,r; cin >> l >> r;
            cout << (T.query(1,1,n,l,r) >= l ? "yes\n" : "no\n");
        }
        return ;
    }
}

namespace Solution4{
    const int N = 1e5+10;
    int st[N][31];
    int lg2[N];
    void solve(){
        int n,m,k;
        cin >> n >> m >> k;
        map<int,int>mp;
        for(int i = 1;i <= n;i ++){
            if(i != 1) lg2[i] = lg2[i>>1]+1;
            int t; cin >> t;
            st[i][0] = mp[t^k];
            mp[t] = i;
        }
        for(int i = 1;i <= 30;i ++){
            for(int j = 1;j+(1<<i)-1 <= n;j ++){
                st[j][i] = max(st[j][i-1],st[j+(1<<i-1)][i-1]);
            }
        }
        auto getmax = [](int l,int r){
            int len = r-l+1;
            return max(st[l][lg2[len]],st[r-(1<<lg2[len])+1][lg2[len]]);
        };
        for(int i = 1;i <= m;i ++){
            int l,r;cin >> l >> r;
            cout << (getmax(l,r) >= l ? "yes\n" : "no\n");
        }
        return ;
    }
}

int main(){
    // cout << (1<<20);
    // Solution2::solve();
    Solution4::solve();
    return 0;
}