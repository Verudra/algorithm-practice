#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c;
    cin >> a >> b >> c;
    auto getAfterString = [](string s, int eps)-> string {
        for(auto& c : s) c = 'A'+(c-'A'+eps+26)%26;
        return s;
    };
    int eps = (b[0]+26-a[0])%26;
    cout << getAfterString(c,-eps);
    return 0;
}