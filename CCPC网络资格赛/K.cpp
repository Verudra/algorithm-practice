#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int a[N];
int ans[N];
int n,res;

int fa[N];
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void join(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) fa[fx]=fy;
}

int main(){
    scanf("%d",&n);
    int cnt=n;
    for(int i=1;i<=n;i++){
        a[i]=cnt--;
    }
    // a[1]=1;
    // a[2]=2;
    // a[3]=3;
    // a[4]=4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fa[j]=j;
        }
        memset(ans,0,sizeof(ans));
        for(int j=0;j<n;j++){
            int x=i+j;
            if(x>n){
                x=x-n;
            }
            join(j+1,a[x]);
        }
        for(int j=1;j<=n;j++){
            if(!ans[find(a[j])]){
                ans[find(a[j])]=1;
                res++;
            }
        }
    }
    printf("%d\n",res);
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }printf("\n");
}