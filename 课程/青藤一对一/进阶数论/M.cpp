#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
int exgcd(int a,int b,int& x,int& y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    int g = exgcd(b,a%b,y,x);
    y -= (a/b)*x;
    return g;
}
int norm(int a,int m){
    return (a%m+m)%m;
}
void work(){
    int L,s1,v1,s2,v2;
    cin >> L >> s1 >> v1 >> s2 >> v2;
    int a = norm(v1-v2,L), c = norm(s2-s1,L);
    int x,y; int g = exgcd(a,L,x,y);
    if(c%g){
        cout << "-1\n";
        return ;
    }
    x *= c/g;
    int step = L/g;
    x = (x%step+step)%step;
    cout << x << '\n';
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