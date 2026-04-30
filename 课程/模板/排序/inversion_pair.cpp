#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int sa[N];
long long ans = 0;
void Merge_sort(int nums[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    Merge_sort(nums, l, mid);
    Merge_sort(nums, mid + 1, r);
    vector<int> vec;
    int i = l, j = mid + 1, cnt = 0;
    while (i <= mid && j <= r)
    {
        if (nums[i] <= nums[j])
        {               // 等于作用是处理存在相等元素的逆序对情况
            ans += cnt; // 放入左侧元素时，逆序对数量增加
            vec.push_back(nums[i++]);
        }
        else
        {
            cnt++; // 放入右侧元素时，记录个数变量自加
            vec.push_back(nums[j++]);
        }
    }
    while (i <= mid)
    {
        ans += cnt; // 别漏了最后的这些逆序对
        vec.push_back(nums[i++]);
    }
    while (j <= r)
        vec.push_back(nums[j++]);
    for (int i = 0; i < vec.size(); i++)
        nums[l + i] = vec[i];
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> sa[i];
    Merge_sort(sa, 1, n);
    cout << ans;
    return 0;
}
