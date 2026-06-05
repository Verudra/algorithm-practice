#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;

ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

struct node{
    ll pos,dis;
    bool operator<(const node&x)const{
        // return x.dis>dis;
        if(x.dis!=dis) return x.dis>dis;
        return x.pos>pos;
    }
};
set<node> se;
struct nd{
    ll x,y,w;
    bool operator<(const nd&aa)const{
        return aa.w<w;
    }
};

ll T,n,k;
ll t[maxn];
ll vis[maxn],cnt;
bool visflg[maxn];
ll ans;

int main(){
    T=read();
    while(T--){
        memset(visflg,0,sizeof(visflg));
        memset(vis,0,sizeof(vis));
        memset(t,0,sizeof(t));
        ans=0;
        cnt=0;
        se.clear();

        n=read();
        k=read();
        for(int i=1;i<=n;i++){
            t[i]=read();
            t[i]%=k;
            if(i!=1) se.insert((node){i,t[i]});
        }
        // printf("count: %d %d\n",se.count({7,2}),se.count({2,1}));
        vis[++cnt]=1;
        visflg[1]=1;
        while(cnt<n){
            // printf("count: %d %d\n",se.count({7,2}),se.count({2,1}));
            // printf("!1\n");
            priority_queue<nd>q;
            for(int i=1;i<=cnt;i++){
                int x=vis[i];
                auto it=se.lower_bound({0,k-t[x]});
                // printf("*it: %d\n",(*it).pos);
                if(it!=se.end()){
                    q.push((nd){x,(*it).pos,((*it).dis+t[x])%k});
                    // printf("! x: %d y: %d dis: %d\n",x,(*it).pos,((*it).dis+t[x])%k);
                }else{
                    it=se.lower_bound({0,0});
                    // printf("!!! it pos: %d id: %d\n",(*it).pos,(*it).dis);
                    // printf("bool: %d\n",se.count({7,2}));
                    q.push((nd){x,(*it).pos,((*it).dis+t[x])%k});
                    // printf("? x: %d y: %d dis: %d\n",x,(*it).pos,((*it).dis+t[x])%k);
                }
            }
            // printf("!2\n");
            while(!q.empty()){
                int x=q.top().x;
                int y=q.top().y;
                int w=q.top().w;
                q.pop();
                if(!visflg[y]){
                    // printf("y: %d w: %d\n",y,w);
                    visflg[y]=1;
                    ans+=w;
                    vis[++cnt]=y;
                    se.erase({y,t[y]});
                    // se.erase(se.find({y,t[y]}));
                    break;
                }
            }
            // printf("cnt: %d\n",cnt);
            // for(int i=1;i<=cnt;i++){
            //     printf("%d ",vis[i]);
            // }printf("\n");
        }
        printf("%lld\n",ans);
    }
}