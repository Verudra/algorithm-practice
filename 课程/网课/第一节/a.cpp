#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=1,m=0; 
    cin >> m;
    int sum = 0;
    while(sum < m){
        sum = sum+n;
        n ++;
    }
    cout << n-1;
    return 0;
}
