#include <bits/stdc++.h>
#define int ll
typedef long long ll;
using namespace std;
const int N = 100005;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
vector<int>vec;
int sa[N],L[N],R[N],rt[N];
vector<vector<int>>ccnt(200005);
ll query1(int pos,int val){
    auto now = ccnt[val];
    if(now.size() == 0) return 0;
    int ppos = lower_bound(now.begin(),now.end(),pos)-now.begin();
    if(ppos == now.size()) return (ll)now.size();
    if(ppos == 0){
        if(now[ppos] > pos) return 0;
        return 1;
    }
    if(now[ppos] == pos) return ppos+1;
    return ppos;
}
ll query(int l,int r,int x){
    return query1(r,x)-query1(l-1,x);
}
ll work(int l,int r,int x,int y,int xx,int yy){
    int mid = (l+r)>>1;
    ll cntx = query(l,mid,x);
    ll cnty = query(mid+1,r,y);
    // printf("!!!%lld\n",query(7,11,3));
    // printf("l:%lld r:%lld mid:%lld y:%d lx:%lld ry:%lld\n",l,r,mid,y,cntx,cnty);
    // printf("%lld %lld")
    ll sum = 0;
    if(cntx > 0 && yy-cnty > 0 && mid-l+1 > 1) sum += work(l,mid,x,y,cntx,yy-cnty);
    if(xx-cntx > 0 && cnty > 0 && r-mid > 1) sum += work(mid+1,r,x,y,xx-cntx,cnty);
    return sum + cntx*cnty;
}
signed main(){
    int n,q;
    // scanf("%lld%lld",&n,&q);
    n=read();
    q=read();
    for(int i = 1;i <= n;i ++){
        // scanf("%lld",&sa[i]);
        sa[i]=read();
        vec.push_back(sa[i]);
    }
    for(int i = 1;i <= q;i ++){
        // scanf("%lld%lld",&L[i],&R[i]);
        L[i]=read();
        R[i]=read();
        vec.push_back(L[i]);
        vec.push_back(R[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 1;i <= n;i ++){
        sa[i] = lower_bound(vec.begin(),vec.end(),sa[i])-vec.begin()+1;
    }
    for(int i = 1;i <= q;i ++){
        L[i] = lower_bound(vec.begin(),vec.end(),L[i])-vec.begin()+1;
        R[i] = lower_bound(vec.begin(),vec.end(),R[i])-vec.begin()+1;
    }
    for(int i = 1;i <= n;i ++){
        // T.change(rt[i-1],rt[i],1,vec.size(),sa[i],1);
        ccnt[sa[i]].push_back(i);
    }
    map<pair<int,int>,ll>mp;
    // printf("!!!%lld\n",query(7,11,3));
    for(int i = 1;i <= q;i ++){
        int x = L[i],y = R[i];
        if(mp.count(make_pair(x,y))) printf("%lld\n",mp[make_pair(x,y)]);
        else{
            ll ans = work(1,n,x,y,query(1,n,x),query(1,n,y));
            mp[make_pair(x,y)] = ans;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
7 4
3 3 3 3 3 3 3
1 2
1 3
1 1
3 3
*/