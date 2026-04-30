#include <bits/stdc++.h>
using namespace std;
struct Time{
    int h,m,s,ss;
    Time(){
        scanf("%d:%d:%d.%d",&h,&m,&s,&ss);
    }
    int getAllss(){
        return ss + s*100 + m*60*100 + h*60*60*100;
    }
};
int main(){
    Time a,b;
    printf("%d",b.getAllss()-a.getAllss());
    return 0;
}