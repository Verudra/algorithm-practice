#include <bits/stdc++.h>
using namespace std;
int n,m,k;
pair<int,int> getpos(int id){
    return make_pair((id-1)/m+1,(id-1)%m+1);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    auto pos = getpos(k);
    // printf("x:%d y:%d",pos.first,pos.second);
    printf("%d %d",pos.first+pos.second-1,abs(n-pos.first)+pos.second);
    return 0;
}