#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
    node operator+(node B){
        node C;
        // 思考一下：这里的a、b没有前缀，用的是谁的呢？
        C.a = a + B.a; 
        C.b = b + B.b;
        return C;
    }
};
int main(){
    node A,B;
    cin >> A.a >> A.b >> B.a >> B.b;
    node C = A + B;
    cout << C.a << ' ' << C.b;
    return 0;
}