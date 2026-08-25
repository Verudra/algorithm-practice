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
struct node{
    int ls,rs,val,dis;
}tre[N];
int sa[N];
bool lesser(int a,int b){
    if(sa[a] != sa[b]) return sa[a] < sa[b];
    return a < b;
}
int merge(int u1,int u2){
    if(!u1) return u2;
    if(!u2) return u1;
    if(lesser(u2,u1)) swap(u1,u2);
    tre[u1].rs = merge(tre[u1].rs,u2);
    if(tre[tre[u1].ls].dis < tre[tre[u1].rs].dis) swap(tre[u1].ls,tre[u1].rs);
    tre[u1].dis = tre[tre[u1].rs].dis+1;
    return u1;
}
void pop(int u){
    tre
}
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
