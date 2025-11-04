#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 0x7f7f7f7f;
bool vis[N];
vector<int>fac[N];
typedef long long ll;
void init(){
    for(int i = 2;i < N;i ++){
        if(!vis[i]){
            for(int j = i;j < N;j += i){
                vis[i] = true;
                fac[j].push_back(i);
            }
        }
    }
    return ;
}
void work(){
    int n;
    scanf("%d",&n);
    vector<int>a(n+1),b(n+1),c;
    vector<int>cnt(N);
    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i ++) scanf("%d",&b[i]);
    c = b;
    sort(c.begin()+1,c.end());
    for(int i = 1;i <= n;i ++){
        for(auto j : fac[a[i]]) cnt[j] ++;
    }
    bool flag = false;
    for(int i = 1;i < N;i ++) if(cnt[i] > 1) flag = true;
    if(flag){
        printf("0\n");
        return ;
    }
    ll minn = c[1] + c[2];
    for(int i = 1;i <= n;i ++){
        for(auto j : fac[a[i]]) cnt[j] --;
        for(auto j : fac[a[i]+1]){
            if(cnt[j] >= 1) minn = min(minn, (ll)b[i]);
        }
        for(auto j : fac[a[i]]) cnt[j] ++;
    }
    int minpos = 0, minw = INF;
    for(int i = 1;i <= n;i ++){
        if(b[i] < minw){
            minpos = i;
            minw = b[i];
        }
    }
    for(int i = 1;i <= n;i ++){
        if(i == minpos) continue;
        for(auto j : fac[a[i]]){
            minn = min(minn, 1ll*(j-a[minpos]%j)*b[minpos]);
        }
    }
    printf("%lld\n",minn);
    return ;
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}

/*
3 29 31
1 1 4
*/