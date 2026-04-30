#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 结果可能非常大，使用 __int128_t 防止溢出
typedef __int128_t int128;

// 用于存储 DP 状态，包含合法后缀的 个数 和 总和
struct Result {
    long long cnt;
    int128 sum;
};

// 记忆化数组 (最高 65 位，奇偶性 2 种)
Result dp[65][2];
bool vis[65][2];
int a[65]; // 存放数字的二进制位

// pos: 当前位 (从右往左，0 是最低位)
// parity: 之前出现 1 的个数的奇偶性 (0为偶数，1为奇数)
// is_limit: 是否受到上限约束
Result dfs(int pos, int parity, bool is_limit) {
    // 边界条件：所有位都填完了
    if (pos < 0) {
        // 如果 1 的总个数是奇数，算作 1 个合法数字，此时无后续位，后缀和为 0
        if (parity == 1) return {1, 0};
        else return {0, 0};
    }
    
    // 如果没有限制，且已经计算过，直接返回记忆化的结果
    if (!is_limit && vis[pos][parity]) {
        return dp[pos][parity];
    }

    Result res = {0, 0};
    // 确定当前位可以填的上限 (受到 limit 约束时只能填到 a[pos]，否则可以填到 1)
    int up = is_limit ? a[pos] : 1;

    // 枚举当前位填 0 还是 1
    for (int i = 0; i <= up; i++) {
        // 递归进入下一位
        Result nxt = dfs(pos - 1, (parity + i) % 2, is_limit && (i == up));
        
        // 累加合法的数字个数
        res.cnt += nxt.cnt;
        
        // 计算当前位产生的价值贡献：数值 * 合法个数
        int128 bit_value = (int128)i * (1ULL << pos);
        // 累加总和：后续低位的和 + 当前位在所有合法情况中产生的总和
        res.sum += nxt.sum + bit_value * nxt.cnt;
    }

    // 记录记忆化状态 (只有在无限制时才记录)
    if (!is_limit) {
        vis[pos][parity] = true;
        dp[pos][parity] = res;
    }
    
    return res;
}

// 求 [1, x] 范围内所有有趣数字的总和
int128 solve(long long x) {
    if (x <= 0) return 0;
    
    int len = 0;
    long long temp = x;
    // 拆分二进制位 (a[0] 是最低位)
    while (temp > 0) {
        a[len++] = temp % 2;
        temp /= 2;
    }
    
    // 从最高位 len-1 开始搜，初始 1 的个数为偶数 (0)，且受到上限限制
    return dfs(len - 1, 0, true).sum;
}

// 辅助函数：输出 __int128_t 类型
void print_int128(int128 n) {
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    string s = "";
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << "\n";
}

int main() {
    // 优化 IO 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r;
    if (cin >> l >> r) {
        // 前缀和思想：求 [l, r] 相当于求 [1, r] - [1, l-1]
        int128 ans = solve(r) - solve(l - 1);
        print_int128(ans);
    }

    return 0;
}