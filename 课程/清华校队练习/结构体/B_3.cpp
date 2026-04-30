#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Patient
{
    string id;
    int age;
    int cnt;
} pt[N];
bool cmp(Patient a, Patient b) // 带条件的排序函数
{
    if (a.age == b.age || a.age < 60 && b.age < 60)
        return a.cnt < b.cnt;
    else
        return a.age > b.age;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pt[i].id >> pt[i].age;
        pt[i].cnt = i;
    }
    sort(pt + 1, pt + 1 + n, cmp); // 注意！cmp后无括号
    for (int i = 1; i <= n; i++)
        cout << pt[i].id << '\n';
    return 0;
}