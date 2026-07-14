#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void dfs(int l1,int r1,int l2,int r2){
    if(l1 > r1) return ;
    char c = s2[r2]; int p = 0;
    cout << c; if(l1 == r1) return ;
    for(int i = l1;i <= r1;i ++) if(s1[i] == c) p = i;
    int lenl = p-l1, lenr = r1-p;
    dfs(l1,p-1,l2,l2+lenl-1);
    dfs(p+1,r1,r2-lenr,r2-1);
    return ;
}
int main(){
    cin >> s1 >> s2;
    dfs(0,s1.length()-1,0,s2.length()-1);
    return 0;
}