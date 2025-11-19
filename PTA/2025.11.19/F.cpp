#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt = 0;
    getchar();
    for(int i = 1;i <= n;i ++){
        string ss;
        getline(cin,ss);
        if(cnt == m){
            cnt = -1;
            cout << ss;
            break;
        }
        cnt ++;
        if(ss.find("qiandao") != ss.npos || ss.find("easy") != ss.npos){
            cnt --;
        } 
    }
    // printf("cnt:%d\n",cnt);
    if(cnt != -1) printf("Wo AK le");
    return 0;
}