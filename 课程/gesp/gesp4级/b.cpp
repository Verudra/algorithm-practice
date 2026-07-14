#include <bits/stdc++.h>
using namespace std;
const int N = 257;
struct node{
    int cnt, id;
}sa[N];
string s[N];
const int INF = 0x7f7f7f7f;
int getnum(char c){
    if(c >= '0' && c <= '9') return c-'0';
    if(c >= 'A' && c <= 'F') return 10+c-'A';
}
int getid(char a,char b){
    return 16*getnum(a) + getnum(b);
}
char getnumc(int x){
    if(x >= 0 && x <= 9) return x+'0';
    else return x-10+'A';
}
string getids(int x){
    // printf("a:%d c:%c  b:%d c:%c\n",x/16,getnumc(x/16),x%16,getnumc(x%16));
    string res = "";
    return (string)""+getnumc(x/16)+getnumc(x%16);
}
char getmindis(char a,char b){
    int id1 = getid(a,b);
    int minn = INF, minpos = -1,minid = -1;
    for(int i = 0;i < 16;i ++){
        if(minn > abs(sa[i].id-id1)){
            minn = abs(sa[i].id-id1);
            minpos = i;
            minid = sa[i].id;
        }
    }
    return getnumc(minpos);
}
int main(){
    int N;
    cin >> N;
    for(int i = 0;i <= 15;i ++){
        for(int j = 0;j <= 15;j ++){
            sa[i*16+j].id = i*16+j;
        }
    }
    for(int i = 1;i <= N;i ++){
        cin >> s[i];
        for(int j = 0;j < s[i].length();j += 2){
            sa[getid(s[i][j],s[i][j+1])].cnt ++;
        }
    }
    sort(sa+0,sa+255+1,[](node a,node b){
        if(a.cnt != b.cnt) return a.cnt > b.cnt;
        return a.id < b.id;
    });
    // for(int i = 0;i < 16;i ++) printf("id:%d cnt:%d\n",sa[i].id,sa[i].cnt);
    for(int i = 0;i < 16;i ++) cout << getids(sa[i].id);
    cout << '\n';
    for(int i = 1;i <= N;i ++){
        for(int j = 0;j < s[i].length();j += 2){
            cout << getmindis(s[i][j],s[i][j+1]);
        }
        cout << '\n';
    }
    return 0;
}