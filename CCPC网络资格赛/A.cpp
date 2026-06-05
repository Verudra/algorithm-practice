#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef long long ll;

ll g(int n, int m, int d){
    ll ans = 0;
    int op = min(d, m);
    int nd = n-d;
    int k = m - n + d;
    op = min(op, m-1);
    if(k > 0){
        if(op >= k){
            ans += k * nd;
            op = op - k;
            ll s = m - k - 1;
            ans += (s*2-op+1)*op/2;
            return ans;
        }
        else return nd*op;
    }
    else{
        ll s = m-1;
        return (s*2-op+1)*op/2;
    }
}

ll work(int n, int m, int a, int b){
    ll ans = 0;
    ans = min(a, b)  + min(a, n-b) + min(n-b, m-a) + min(b, m-a);
    ans += max(g(n, m-a, b), g(n, m-a, n-b)) + max(g(n, a, b), g(n, a, n-b));
    ans += max(g(m, n-b, a), g(m, n-b, m-a)) + max(g(m, b, a), g(m, b, m-a));
    return ans;
}

int n, m;
int main(){
    scanf("%d%d", &n, &m);
    vector<vector<ll > >vec(n+1, vector<ll>(m+1, 0));
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            vec[i][j] = work(n, m, j, i);
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++) printf("%lld ", vec[i][j]);
        printf("\n");
    }
    return 0;
}