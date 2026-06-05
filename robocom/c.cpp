#include <bits/stdc++.h>
using namespace std;
list<char>li;
int pre[1000005];
bool flag[1000005];
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 0;i < s2.length();i ++) pre[i] = i;
    int cnt = 0;
    for(int i = 0;i < s2.length()-1;i ++){
        if(flag[i] == true) continue;
        if(s2[i] == s1[0] && s2[i+1] == s1[1]){
            int l = i,r = i+1;
            while(l >= 0 && r < s2.length() && s2[l] == s1[0] && s2[r] == s1[1]){
                cnt ++;
                flag[l] = true;
                flag[r] = true;
                if(l == 0) l = -1;
                else l = pre[l-1];
                r ++;
            }
            int to = pre[l];
            for(int j = l+1;j < r;j ++) pre[j] = to;
        }
    }
    printf("%d ",cnt);
    for(int i = 0;i < s2.length();i ++){
        if(flag[i] == false) printf("%c",s2[i]);
    }
    return 0;
}