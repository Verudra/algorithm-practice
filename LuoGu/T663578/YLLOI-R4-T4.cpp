#include <bits/stdc++.h>
using namespace std;
const int N = (1<<17)-1 + 100;
int L[N], R[N];
int n,root,k;
// int rdep[N];
int itim[N], otim[N];
int roots[N],nodeRDep[N];
vector<int> rdep[N],ans;
int lftim, cnt;
const int INF = 0x7f7f7f7f;
struct PSTtree{
    struct{ int l,r,val; }tre[N*25];
    int update(int u,int l,int r,int pos,int val){
        int dir = ++cnt;
        tre[dir] = tre[u];
        tre[dir].val = min(tre[dir].val, val);
        if(l == r) return dir;
        int mid = l+r>>1;
        if(pos <= mid) tre[dir].l = update(tre[u].l,l,mid,pos,val);
        else tre[dir].r = update(tre[u].r,mid+1,r,pos,val);
        return dir;
    }
    int query(int u,int l,int r,int cl,int cr){
        if(!u || cl > r || cr < l) return INF;
        if(l >= cl && r <= cr) return tre[u].val;
        int mid = l+r>>1;
        int res = INF;
        if(cl <= mid) res = min(res,query(tre[u].l,l,mid,cl,cr));
        if(cr > mid) res = min(res,query(tre[u].r,mid+1,r,cl,cr)); 
        return res;
    }
}T;
void dfs1(int u,int rdp){
    nodeRDep[u] = rdp;
    if(!L[u] && !R[u]){
        rdep[rdp].push_back(u);
        itim[u] = otim[u] = ++lftim;
        return ;
    }
    itim[u] = lftim+1;
    dfs1(L[u],rdp);
    dfs1(R[u],rdp+1);
    otim[u] = lftim;
    return ;
}
void dfsA(int u){
    ans.push_back(u);
    if(!L[u]&&!R[u]) return ;
    if(k && L[u] > R[u]){
        swap(L[u],R[u]);
        k --;
    }
    dfsA(L[u]);
    dfsA(R[u]);
}
int query_leaf(int u,int resk){
    if(!u) return INF;
    if(!L[u] && !R[u]) return u;
    int d = min(resk+nodeRDep[u],n);
    return T.query(roots[d],1,lftim,itim[u],otim[u]);
}
void dfsB(int u){
    if(!L[u] && !R[u]){
        ans.push_back(u);
        return ;
    }
    int lans = query_leaf(L[u],k);
    int rans = k>0?query_leaf(R[u],k-1):INF;
    if(lans > rans){
        swap(L[u],R[u]);
        k --;
    }
    dfsB(L[u]);
    ans.push_back(u); 
    dfsB(R[u]);
}
void dfsC(int u){
    if(!L[u] && !R[u]){
        ans.push_back(u);
        return ;
    }
    int lans = query_leaf(L[u],k);
    int rans = k>0?query_leaf(R[u],k-1):INF;
    if(lans > rans){
        swap(L[u],R[u]);
        k --;
    }
    dfsC(L[u]);
    dfsC(R[u]);
    ans.push_back(u);
}
int main(){
    char c = getchar();
    scanf("%d%d%d",&n,&root,&k);
    if(k > n) k = n;
    for(int i = 1;i <= n;i ++) scanf("%d%d",&L[i],&R[i]);
    if(c == 'B' || c == 'C'){
        T.tre[0].val = INF;
        dfs1(root, 0);
        for(int i = 0;i <= n;i ++){
            roots[i] = i==0 ? 0:roots[i-1];
            for(auto j : rdep[i]){
                roots[i] = T.update(roots[i],1,lftim,itim[j],j);
            }
        }
    }
    ans.reserve(n);
    if(c == 'A') dfsA(root);
    else if(c == 'B') dfsB(root);
    else if(c == 'C') dfsC(root);
    for(int i = 0;i < n;i ++){
        printf("%d%c",ans[i],i==n-1 ? '\n' : ' ');
    }
    return 0;
}