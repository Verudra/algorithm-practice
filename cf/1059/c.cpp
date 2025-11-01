#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int a,b;
        scanf("%d%d",&a,&b);
        int cnta = 31-__builtin_clz(a), cntb = 31-__builtin_clz(b);
        int cnt = 0;
        vector<int>ans;
        if(cnta < cntb) printf("-1\n");
        else{
            while(a){
                if((a&1) != (b&1)) ans.push_back(1<<cnt);
                cnt ++;
                a >>= 1; b >>= 1;
            }
            printf("%d\n",ans.size());
            for(auto i : ans) printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}