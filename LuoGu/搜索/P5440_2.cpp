#include <bits/stdc++.h>
using namespace std;
int A[101];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        A[t]++;
    }
    int mx = 0;
    int mxid = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (A[i] > mx)
        {
            mx = A[i];
            mxid = i;
        }
        cout << mxid;
    }

    return 0;
}