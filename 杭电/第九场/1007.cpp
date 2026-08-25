#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <utility>
#include <vector>
using namespace std;

const int P1 = 1000000007;
const int P2 = 1000000009;

struct Op {
    int type, x, y, z;
};

struct BIT {
    int n;
    vector<int> t1, t2;

    BIT(int n): n(n), t1(n + 1), t2(n + 1) {}

    void add(int x, int v1, int v2) {
        for(int i = x; i <= n; i += i & -i) {
            t1[i] += v1;
            if(t1[i] >= P1) t1[i] -= P1;
            if(t1[i] < 0) t1[i] += P1;

            t2[i] += v2;
            if(t2[i] >= P2) t2[i] -= P2;
            if(t2[i] < 0) t2[i] += P2;
        }
    }

    pair<int, int> sum(int x) {
        int s1 = 0, s2 = 0;
        for(int i = x; i > 0; i -= i & -i) {
            s1 += t1[i];
            if(s1 >= P1) s1 -= P1;
            s2 += t2[i];
            if(s2 >= P2) s2 -= P2;
        }
        return {s1, s2};
    }

    bool zero(int l, int r) {
        auto a = sum(r);
        auto b = sum(l - 1);
        return a.first == b.first && a.second == b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    int T;
    cin >> T;
    while(T--) {
        int n, q, k;
        cin >> n >> q >> k;

        vector<int> a(n + 1), c(n + 1);
        vector<int> values(n);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            values[i - 1] = a[i];
        }
        for(int i = 1; i <= n; i++) cin >> c[i];

        // 先读完操作，收集修改中可能出现的所有编号。
        vector<Op> ops(q);
        for(auto &o: ops) {
            cin >> o.type;
            if(o.type == 1) {
                cin >> o.x >> o.y >> o.z;
                values.push_back(o.y);
            } else {
                cin >> o.x >> o.y;
                o.z = 0;
            }
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        for(int i = 1; i <= n; i++) {
            a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
        }
        for(auto &o: ops) {
            if(o.type == 1) {
                o.y = lower_bound(values.begin(), values.end(), o.y) - values.begin();
            }
        }

        int m = values.size();
        vector<int> h1(m), h2(m);
        for(int i = 0; i < m; i++) {
            h1[i] = rng() % P1;
            h2[i] = rng() % P2;
        }

        // 强制所有口味权值之和为 0。
        vector<int> w1(k), w2(k);
        long long s1 = 0, s2 = 0;
        for(int i = 0; i + 1 < k; i++) {
            w1[i] = rng() % P1;
            w2[i] = rng() % P2;
            s1 += w1[i];
            s2 += w2[i];
            if(s1 >= P1) s1 -= P1;
            if(s2 >= P2) s2 -= P2;
        }
        w1[k - 1] = (P1 - s1) % P1;
        w2[k - 1] = (P2 - s2) % P2;

        auto get = [&](int x, int col) {
            int v1 = 1LL * h1[x] * w1[col] % P1;
            int v2 = 1LL * h2[x] * w2[col] % P2;
            return pair<int, int>(v1, v2);
        };

        // 先放入每个位置的值，再在线性时间内建树状数组。
        BIT bit(n);
        for(int i = 1; i <= n; i++) {
            auto v = get(a[i], c[i]);
            bit.t1[i] = v.first;
            bit.t2[i] = v.second;
        }
        for(int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if(j <= n) {
                bit.t1[j] += bit.t1[i];
                if(bit.t1[j] >= P1) bit.t1[j] -= P1;
                bit.t2[j] += bit.t2[i];
                if(bit.t2[j] >= P2) bit.t2[j] -= P2;
            }
        }

        for(auto o: ops) {
            if(o.type == 1) {
                int p = o.x;
                auto oldv = get(a[p], c[p]);
                auto newv = get(o.y, o.z);
                bit.add(p, newv.first - oldv.first, newv.second - oldv.second);
                a[p] = o.y;
                c[p] = o.z;
            } else {
                bool ok = (o.y - o.x + 1) % k == 0 && bit.zero(o.x, o.y);
                cout << (ok ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}
