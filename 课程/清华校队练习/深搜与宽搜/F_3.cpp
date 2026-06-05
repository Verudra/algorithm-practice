#include <bits/stdc++.h>
using namespace std;

const int MAXP = 100000;
int dista[MAXP + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    fill(dista, dista + MAXP + 1, -1);

    queue<int> q;
    q.push(n);
    dista[n] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k) {
            cout << dista[x] << '\n';
            return 0;
        }

        int nxt[3] = {x - 1, x + 1, x * 2};
        for (int i = 0; i < 3; i++) {
            int y = nxt[i];
            if (y < 0 || y > MAXP || dista[y] != -1) continue;

            dista[y] = dista[x] + 1;
            q.push(y);
        }
    }

    return 0;
}
