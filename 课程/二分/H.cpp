#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int main(){
    int l,n,m;
    scanf("%d%d%d",&l,&n,&m);
    vector<int>v(n);
    int pre = 0;
    for(auto& i : v) scanf("%d",&i) , pre = i;
    int L = 1, R = l;
    while(L < R){
        int mid = L+R+1>>1;
        auto check = [&](int mid)->bool {
            int cnt = 0, pre = 0;
            for(auto i : v){
                if(i-pre < mid) cnt ++;
                else pre = i;
            }
            if(l-pre < mid) cnt ++;
            if(cnt > m) return false;
            return true;
        }; 
        if(check(mid)) L = mid;
        else R = mid-1;
    }
    printf("%d",L);
    return 0;
}