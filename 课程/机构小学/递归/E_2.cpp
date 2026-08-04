#include<bits/stdc++.h>
using namespace std;
int n; 
int fun(int u){
    if(u>n) return 0;
    int res = 0;
    if(u <= n && u != 0) res = 1;
    return fun(u*10+4)+fun(u*10+7)+res;
}
int main(){
    cin>>n;
    cout<<fun(0);
    return 0;
}