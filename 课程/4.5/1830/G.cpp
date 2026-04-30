#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 题目规定最大数字为 100000
const int MAXA = 100005;
int spf[MAXA]; // 存储每个数的最小质因数

// 预处理求最小质因数 (用于 $O(\log N)$ 快速分解质因数)
void precompute() {
    for (int i = 2; i < MAXA; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    // 算法竞赛常规的 I/O 优化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();

    int n;
    if (!(cin >> n)) return 0;

    // prime_exponents[p] 存放所有包含质因数 p 的元素的对应指数
    vector<vector<int>> prime_exponents(MAXA);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // 快速质因数分解
        while (a > 1) {
            int p = spf[a];
            int count = 0;
            while (a % p == 0) {
                count++;
                a /= p;
            }
            prime_exponents[p].push_back(count);
        }
    }

    long long total_ops = 0; // 记录总操作花费的最小金币数量

    // 独立处理每一个质数
    for (int p = 2; p < MAXA; p++) {
        if (prime_exponents[p].empty()) continue;

        auto& exp = prime_exponents[p];
        // 升序排序
        sort(exp.begin(), exp.end());

        int k = exp.size();       // 该质数在 k 个数中非0
        int zeros = n - k;        // 在 n-k 个数中指数为 0
        int mid = n / 2;          // 长度为 n 的序列的中位数下标 (0-indexed)

        long long median = 0;
        // 判定中位数是多少：
        // 如果 mid 下标落在了前面的 0 的区域内，中位数为 0
        // 否则，落在非零数组区域，进行偏移获取
        if (mid >= zeros) {
            median = exp[mid - zeros];
        }

        long long cost = 0;
        // 1. 处理那些原本指数为 0 的元素的代价 (|0 - median| = median)
        cost += 1LL * zeros * median;
        
        // 2. 处理指数非 0 的元素的代价
        for (int x : exp) {
            cost += abs(x - median);
        }
        
        total_ops += cost;
    }

    cout << total_ops << "\n";
    return 0;
}