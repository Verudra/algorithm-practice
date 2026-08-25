#include <bits/stdc++.h>
using namespace std;
int A[1010];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    int t = A[1];
    for (int i = 2; i <= n; i++)
    {
        A[i - 1] = A[i];
    }
    A[n] = t;
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << ' ';
    }
    return 0;
}
