#include <iostream>
#include <algorithm>

using namespace std;

// 使用 __uint128_t 防止乘法溢出
using u64 = unsigned long long;
using u128 = __uint128_t;

// 快速幂
u64 power(u64 base, u64 exp, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (u128)res * base % mod;
        base = (u128)base * base % mod;
        exp /= 2;
    }
    return res;
}

// Miller-Rabin 素性测试 (O(k * log n) 复杂度，非常适合处理大素数判断)
bool is_prime(u64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    u64 d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // 针对 64位 整数的底数集合，可以保证 100% 准确率
    static const u64 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (u64 a : bases) {
        if (n <= a) break;
        u64 x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

void solve() {
    long long h;
    cin >> h;
    
    long long min_attacks = -1;

    // 枚举物理攻击的次数 k (由于 h 都在 long long 范围内，k 最多到 61 左右)
    for (int k = 0; ; ++k) {
        long long phys_dmg = (1LL << k) - 1; // 2^k - 1
        
        if (phys_dmg > h) {
            break; // 物理伤害已经超过怪物血量，退出枚举
        }

        long long rem = h - phys_dmg;

        // 情况 A: 恰好用纯物理攻击击杀
        if (rem == 0) {
            if (min_attacks == -1 || k < min_attacks) {
                min_attacks = k;
            }
        } 
        // 情况 B: 剩余血量是一个质数，可以用 1 次魔法攻击收尾
        else if (is_prime(rem)) {
            if (min_attacks == -1 || k + 1 < min_attacks) {
                min_attacks = k + 1;
            }
        }
    }

    cout << min_attacks << "\n";
}

int main() {
    // 算法竞赛常用的 I/O 优化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}