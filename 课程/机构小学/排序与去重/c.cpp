#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N];
bool cmp(int a,int b){
    return abs(a) > abs(b);
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    sort(sa+1,sa+1+n,cmp);
    for(int i = 1;i <= n;i ++) cout << sa[i] << ' ';
    return 0;
}