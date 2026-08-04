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
void dfs(int n,char a,char b,char c){
    if(n == 1){
        printf("%c->%d->%c\n",a,n,c);
        return ;
    }    
    dfs(n-1,a,c,b);
    printf("%c->%d->%c\n",a,n,c);
    dfs(n-1,b,a,c);
    return ;
}
void work(){
    int n; cin >> n;
    printf("%d\n",(1<<n)-1);
    dfs(n,'a','b','c');
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}