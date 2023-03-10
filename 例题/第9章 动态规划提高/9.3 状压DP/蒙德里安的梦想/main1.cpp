#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 11;

int n, m;
bool ok[1<<M];
ll f[M + 5][1<<M];

void work() {
    for (int i = 0; i < (1<<m); i++) {
        bool odd = false;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                if (odd) break;
                else odd = false;
            }
            else odd ^= 1;
        }
        ok[i] = !odd;
    }
    for (int i = 0; i < (1<<m); i++) f[0][i] = ok[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < (1<<m); j++) {
            f[i][j] = 0;
            for (int k = 0; k < (1<<m); k++) if (!(j & k) && ok[j | k]) f[i][j] += f[i - 1][k];
        }

    }
    printf("%lld\n", f[n - 1][0]);
}

int main() {
    while (~scanf("%d %d", &n, &m) && n + m) work();
    return 0;
}