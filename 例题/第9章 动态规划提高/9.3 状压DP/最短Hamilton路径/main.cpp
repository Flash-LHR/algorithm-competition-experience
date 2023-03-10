#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

const int M = int(2e1);

int a[M][M];
int f[1<<M][M];

void work() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < (1<<n); i++) memset(f[i], inf, sizeof(f[i][0]) * n);
    f[1][0] = 0;
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            for (int k = 0; k < n; k++) if (!(i >> k & 1)) {
                cmin(f[i|(1<<k)][k], f[i][j] + a[j][k]);
            }
        }
    }
    printf("%d\n", f[(1<<n) - 1][n - 1]);
}

int main() {
    work();
    return 0;
}