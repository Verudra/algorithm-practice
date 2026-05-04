#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
struct node{ // 优先a升序，再按照b升序，再按照c升序
    int a,b,c;
    bool operator<(node B){
        if(a != B.a) return a < B.a;
        if(b != B.b) return b < B.b;
        return c < B.c;
    }
}sa[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i].a >> sa[i].b >> sa[i].c;
    }
    sort(sa+1,sa+1+n);
    for(int i = 1;i <= n;i ++){
        cout << sa[i].a << ' ' << sa[i].b  << ' ' << sa[i].c << '\n';
    }
    return 0;
}