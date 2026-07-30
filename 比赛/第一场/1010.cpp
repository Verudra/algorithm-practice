#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){int ret =0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-f;for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+(ch&15);return ret*f;}

const int N = 1e6+10,maxe = N<<1,maxn = N;
int a[N],lft[N],rght[N],len[N];
int son[maxe],f[N],b[maxe],tot;
struct AC{
    int  id,x;
    bool operator <(const AC &b)const{return x <=b.x;}
};
vector <int> v[maxn];
map<int,bool> mp[maxn];
inline void init(){
    int n = read();int S1=0,S2=0,sum=0;
    if(n == 2){
        read();read();
        puts("YES");return;
    }
    for(int i =1;i<=(n)/2;i++){
        sum+=(a[i] = read());
        S1 +=sum;
    }
    sum  = 0;read();
    for(int i =1;i<=(n-1)/2;i++){
        S2+= i * read();
    }
    if(S1 > S2) puts("YES");
    else if(S1 == S2){
        if(n%2 == 0) puts("YES");
        else puts("NO");
    }
    else puts("NO");
}
signed main(){
    for(int t = read(); t--;)init();
}