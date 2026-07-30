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
struct Tree_Sequence{
    int sa[N],tre[N];
    int lowbit(int x){
        return x&-x;
    }
    void add(int pos,int val){
        if(pos == 0){
            cout << "Warning!";
            return ;
        }
        sa[pos] += val;
        while(pos < N){
            tre[pos] += val;
            pos += lowbit(pos);
        }
        return ;
    }
    void build(const vector<int>&v){
        for(int i = 0;i < v.size();i ++){
            add(i+1,v[i]);
        }
    }
    int query(int pos){
        int res = 0;
        while(pos){
            res += tre[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    int query(int l,int r){
        return query(r) - query(l-1);
    }
    void change(int pos,int val){
        add(pos,val-sa[pos]);
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