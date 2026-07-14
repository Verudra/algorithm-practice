#include <bits/stdc++.h>
using namespace std;
struct node{
    int h,w;
    int id1,id2;
};
long long cnt = 0;
void mysort(int l,int r,vector<node>& v){
    if(l >= r) return ;
    int mid = l+r>>1;
    int p1 = l, p2 = mid+1;
    mysort(l,mid,v); mysort(mid+1,r,v);
    int cntr = 0;
    vector<int>tv;
    while(p1 <= mid && p2 <= r){
        if(v[p1].id2<=v[p2].id2){
            cnt += cntr;
            tv.push_back(v[p1++].id2);
        }
        else{
            cntr ++;
            tv.push_back(v[p2++].id2);
        }
        // tv.push_back((v[p1].id2<=v[p2].id2)?cnt+=cntr,v[p1++].id2:cntr++,v[p2++].id2);
    }
    while(p1 <= mid) tv.push_back(v[p1++].id2),cnt+=cntr;
    while(p2 <= r) tv.push_back(v[p2++].id2);
    for(int i = 0;i < tv.size();i ++) v[l+i].id2 = tv[i];
}
int main(){
    int n;
    cin >> n;
    vector<node>v;
    for(int i = 1;i <= n;i ++){
        node t;cin >> t.h >> t.w;
        t.id1 = i;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),[](node a,node b){
        if(a.h != b.h) return a.h > b.h;
        if(a.w != b.w) return a.w > b.w;
        return a.id1 < b.id1;
    });
    for(int i = 0;i < v.size();i ++) v[i].id2 = i+1;
    sort(v.begin(),v.end(),[](node a,node b){
        return a.id1 < b.id1;
    });
    mysort(0,v.size()-1,v);
    cout << cnt;
    return 0;
}