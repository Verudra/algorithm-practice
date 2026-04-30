#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 优化标准输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // cost[i] 存储初始属于武器 i 的所有材料的修改花费
    vector<vector<long long>> cost(n + 1);
    for (int i = 0; i < m; i++) {
        int p;
        long long c;
        cin >> p >> c;
        cost[p].push_back(c);
    }

    // 对除了武器 1 以外的其他武器的材料花费进行升序排序
    for (int i = 2; i <= n; i++) {
        sort(cost[i].begin(), cost[i].end());
    }

    long long ans = -1;

    // 枚举武器 1 最终的材料数量 k
    for (int k = 1; k <= m; k++) {
        long long current_cost = 0;
        int current_1_cnt = cost[1].size(); // 武器 1 初始就有的材料数
        
        // pool 用于存放那些没有被强制抢走，可以用来凑数“自由填补”的备选材料花费
        vector<long long> pool;

        // 1. 强制剥夺阶段
        for (int i = 2; i <= n; i++) {
            int sz = cost[i].size();
            // 如果该武器拥有材料数 >= k，必须抢走多余的部分，使其剩下 k-1 个
            int take = max(0, sz - (k - 1)); 
            
            current_1_cnt += take;
            // 贪心：抢走花费最小的 take 个
            for (int j = 0; j < take; j++) {
                current_cost += cost[i][j];
            }
            // 剩下的材料放入备选池中
            for (int j = take; j < sz; j++) {
                pool.push_back(cost[i][j]);
            }
        }

        // 2. 自由填补阶段
        // 如果强制抢完后，武器 1 的材料依然不够 k 个
        if (current_1_cnt < k) {
            // 对备选池里的材料花费进行排序，挑最便宜的买
            sort(pool.begin(), pool.end());
            int need = k - current_1_cnt;
            
            for (int i = 0; i < need; i++) {
                current_cost += pool[i];
            }
        }

        // 更新全局最小花费
        if (ans == -1 || current_cost < ans) {
            ans = current_cost;
        }
    }

    cout << ans << "\n";
    return 0;
}