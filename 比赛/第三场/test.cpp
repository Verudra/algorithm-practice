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
const int N = 2e5+10;
struct Segment_Tree{
    #define mid ((l+r)/2)
    int tot;
    struct node{
        int ls,rs,val,pos;
    };
    node tre[N<<2];
    void init(){
        tot = 1;
    }
    node max(node a,node b){
        if(a.val != b.val){
            node res;
            if(a.val < b.val){ res = b;}
            else{ res = a;}
            return res;
        }
        if(a.pos < b.pos) return a;
        return b;
    }
    void update(int u){
        tre[u] = max(tre[tre[u].ls],tre[tre[u].rs]);
        return ;
    }
    int add(){
        tot ++;
        tre[tot].ls = tre[tot].rs = tre[tot].val = 0;
        return tot;
    }
    void change(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u].val = std::max(tre[u].val, val);
            tre[u].pos = l;
            cout << "update pos:" << l << ' ' << "val:" << val << '\n';
            return ;
        }
        if(pos <= mid){
            if(!tre[u].ls) tre[u].ls = add();
            change(tre[u].ls,l,mid,pos,val);
            printf("update u:%lld l:%lld r:%lld pos:%lld val:%lld tre.ls:%lld tre.rs:%lld\n",u,l,r,pos,val,tre[u].ls,tre[u].rs);
        }
        else{
            if(!tre[u].rs) tre[u].rs = add();
            change(tre[u].rs,mid+1,r,pos,val);
            printf("update u:%lld l:%lld r:%lld pos:%lld val:%lld tre.ls:%lld tre.rs:%lld\n",u,l,r,pos,val,tre[u].ls,tre[u].rs);
        }
        update(u);
        printf("update u:%lld l:%lld r:%lld pos:%lld val:%lld tre.ls:%lld tre.rs:%lld\n",u,l,r,pos,val,tre[u].ls,tre[u].rs);
    }
    node query(int u,int l,int r,int cl,int cr){
        cout << "query u:" << u << " l:" << l << ' ' << "r:" << r << " tre.val" << tre[u].val << " tre.pos" << tre[u].pos << '\n';

        if(l >= cl && r <= cr){
            cout << "stop tre.val:" << tre[u].val << '\n';
            return tre[u];
        }
        node res={0,0,0,0};
        cout << "u:" << u << " mid:" << mid << " tre.ls" << tre[u].ls << " tre.rs" << tre[u].rs << '\n';
        if(cl <= mid && tre[u].ls) res = query(tre[u].ls, l,mid,cl,cr);
        if(cr > mid && tre[u].rs) res = max(res,query(tre[u].rs,mid+1,r,cl,cr));
        return res;
    }
}tt;

void work(){
    tt.init();
    tt.change(1,1,4,1,2);
    cout << tt.query(1,1,4,1,1).val;
    return ;
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}