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
struct ST_max{
    int st[N][23];
    int lg2[N];
    int merge(int a,int b){
        return max(a,b);
    }
    int query(int l,int r){
        int len = r-l+1;
        int cm = lg2[len];
        return merge(st[l][cm],st[r-(1LL<<cm)+1][cm]);
    }
    void build(const vector<int>& v){
        int n = v.size();
        for(int i = 2;i <= n;i ++) lg2[i] = lg2[i/2]+1;
        for(int i = 0;i < n;i ++){
            st[i+1][0] = v[i];
        }
        for(int k = 1;(1LL<<k) <= n;k ++){
            for(int i = 1;i+(1LL<<k)-1 <= n;i ++){
                st[i][k] = merge(st[i][k-1],st[i+(1LL<<(k-1))][k-1]);
            }
        }
        return ;
    }
};
struct ST_min{
    int st[N][23];
    int lg2[N];
    int merge(int a,int b){
        return min(a,b);
    }
    int query(int l,int r){
        int len = r-l+1;
        int cm = lg2[len];
        return merge(st[l][cm],st[r-(1LL<<cm)+1][cm]);
    }
    void build(const vector<int>& v){
        int n = v.size();
        for(int i = 2;i <= n;i ++) lg2[i] = lg2[i/2]+1;
        for(int i = 0;i < n;i ++){
            st[i+1][0] = v[i];
        }
        for(int k = 1;(1LL<<k) <= n;k ++){
            for(int i = 1;i+(1LL<<k)-1 <= n;i ++){
                st[i][k] = merge(st[i][k-1],st[i+(1LL<<(k-1))][k-1]);
            }
        }
        return ;
    }
};

void work(){
    
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}