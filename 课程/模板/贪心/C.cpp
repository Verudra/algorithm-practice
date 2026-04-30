#include <bits/stdc++.h>
using namespace std;
struct Hero
{
    int dps;
    int hp;
};
// 贪心排序比较函数
// 比较先杀 a 后杀 b 还是先杀 b 后杀 a 受到的额外伤害更小
// 避免浮点数除法，使用交叉相乘：hp_a * dps_b < hp_b * dps_a
bool compareHeroes(const Hero &a, const Hero &b)
{
    return a.hp * b.dps < b.hp * a.dps;
}

void solve()
{
    int n;
    while (cin >> n)
    {
        vector<Hero> heroes(n); 
        long long total_dps = 0; // 算总的DPS
        for (int i = 0; i < n; ++i)
        {
            cin >> heroes[i].dps >> heroes[i].hp;
            total_dps += heroes[i].dps; 
        }
        // 按贪心策略排序
        sort(heroes.begin(), heroes.end(), compareHeroes);

        long long total_loss = 0;
        // 模拟击杀过程
        for (int i = 0; i < n; ++i)
        {
            // 击杀当前英雄需要的时间等于其 hp (因为你的 DPS 为 1)
            total_loss += (long long)heroes[i].hp * total_dps;
            // 杀掉该英雄后，它不再贡献 DPS
            total_dps -= heroes[i].dps;
        }

        cout << total_loss << endl;
    }
}

int main()
{
    // 优化输入输出，这个写法先看看学习一下，以后会用到。
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}