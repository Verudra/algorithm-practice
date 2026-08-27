#include<bits/stdc++.h>
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
void work(){
    int n,x1,y1,x2,y2; cin >> n >> x1 >> y1 >> x2 >> y2;
    char Ax = 'A', Bx = 'B', Ay = 'A', By = 'B';
    if(x1 > x2) swap(Ax,Bx);
    if(y1 > y2) swap(Ay,By);
    string s; cin >> s;
    vector<char> op; int x=0,y=0;
    for(auto c : s){
        if(c == 'L') op.push_back(Ax),x ++;
        if(c == 'R') op.push_back(Bx),x ++;
        if(c == 'U') op.push_back(Ay),y ++;
        if(c == 'D') op.push_back(By),y ++;
    }
    cout << abs(x2-x1)+x+abs(y2-y1)+y << '\n';
    for(auto c : op) cout << c;
    cout << '\n';
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