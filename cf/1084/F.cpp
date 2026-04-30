#include <bits/stdc++.h>
using namespace std;
void work()
{
    /*
        n: 已有粒子个数
        m: 商店中的粒子个数
        x: 粒子能量
        y: 粒子反应性，最多共存粒子数量（除自己）
        vec1: vector<pair<val1:ll, val2:ll>>
            val1和val2分别对应已有粒子的能量和反应性
        vec2: vector<pair<val1:ll, val2:ll>>
            val1,val2分别记录商店粒子的能量和反应性
        now: 不考虑商店粒子时，实时维护的堆中所有粒子价值
        maxn: 不考虑商店粒子的最大价值
        pq: 小根堆，用于维护k大价值的粒子
        cmp: 比较函数，按粒子反应性升序排序
        p1: 一个指针，指向未进堆的最具反应性粒子
        f[i]: 解集大小不大于i，且只用不多于i-1个已有粒子，空出位置给商店粒子的最大价值
    */
    typedef long long ll;
    int n, m;
    ll x, y;
    ll now = 0, maxn = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    auto cmp = [&](pair<ll, int> a, pair<ll, int> b) -> bool
    {
        return a.second < b.second;
    };

    // 读入
    scanf("%d%d", &n, &m);
    int p1 = n;
    vector<pair<ll, int>> vec1(n + 1), vec2(m + 1);
    vector<ll> f(n + 2); // 注意这里是n+2，因为加上商店粒子后最多有n+1个粒子，会用到n+1这个下标
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x, &y);
        vec1[i] = make_pair(x, y);
    }
    sort(vec1.begin(), vec1.end(), cmp); // 按照反应性升序排序
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &x, &y);
        vec2[i] = make_pair(x, y);
    }

    // 第一次处理
    for (int k = n; k >= 1; k--)
    {
        while (p1 >= 1 && vec1[p1].second + 1 >= k)
        { // 把反应性限制允许的粒子全部加入
            pq.push(vec1[p1].first);
            now += vec1[p1].first;
            p1--;
        }
        while (pq.size() > k)
        { // 保证只留最大的k个粒子
            now -= pq.top();
            pq.pop();
        }
        maxn = max(maxn, now);
    }
    while (!pq.empty()) // 清空一下堆，为下一轮做准备
        pq.pop();
    p1 = n;
    now = 0;
    for (int k = n + 1; k >= 1; k--)
    {
        while (p1 >= 1 && vec1[p1].second + 1 >= k)
        { //  和第一轮一样
            pq.push(vec1[p1].first);
            now += vec1[p1].first;
            p1--;
        }
        while (pq.size() > k - 1)
        { // 注意空出一个位置给商店粒子
            now -= pq.top();
            pq.pop();
        }
        f[k] = now;
    }
    for (int i = 2; i <= n + 1; i++)
    { // 处理一下前缀最大值，因为商店粒子(x,y)可以放到所有反应性限制不超过y的解集中
        f[i] = max(f[i], f[i - 1]);
    }
    for (int i = 1; i <= m; i++)
    { // 输出答案，不一定用商店粒子，两者取较大即可
        printf("%lld ", max(f[vec2[i].second + 1] + vec2[i].first, maxn));
    }
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        work();
    }
    return 0;
}