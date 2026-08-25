#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    string st;
    for (char c : s)
    {
        while (k && !st.empty() && st.back() > c)
            st.pop_back(), k--;
        st.push_back(c);
    }
    while (k-- && !st.empty())
        st.pop_back();
    int p = 0;
    while (p + 1 < st.size() && st[p] == '0')
        p++;
    cout << (st.empty() ? "0" : st.substr(p)) << "\n";
}