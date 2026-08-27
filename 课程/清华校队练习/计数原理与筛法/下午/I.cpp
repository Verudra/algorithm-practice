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
int n;
const int N = 10050;
vi prims; bool vis[N];
void init(){
    for(int i = 2;i <= 10000;i ++){
        if(!vis[i]){
            prims.push_back(i);
            for(int j = i*2;j <= 10000;j += i){
                vis[j] = true;
            }
        }
    }
    return ;
}
void work(){
    int l = 0,r = -1;
    int sum = 0;
    int cnt = 0;
    while(l < prims.size()){
        while(r < (int)prims.size() && sum < n) sum += prims[++r];
        if(sum == n) cnt ++;
        sum -= prims[l++];
    }
    cout << cnt << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T=1; 
    //cin >> T;
    while(cin >> n){
        if(n == 0) break;
        work();
    }
    return 0;
}