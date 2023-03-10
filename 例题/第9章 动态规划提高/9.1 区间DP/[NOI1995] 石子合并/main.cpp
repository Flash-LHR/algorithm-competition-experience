#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(2e2);
const int inf = 0x3f3f3f3f;

int a[M + 5];
int s[M + 5];
int f[M + 5][M + 5];
int g[M + 5][M + 5];

void work() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
    memset(f, inf, sizeof f), memset(g, -inf, sizeof g);
    for (int i = 1; i < 2 * n; ++i) s[i] = s[i - 1] + a[i], f[i][i] = g[i][i] = 0;
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l + len - 1 < 2 * n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k)
                cmin(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]),
                cmax(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
        }
    }
    int mi = inf, mx = -inf;
    for (int i = 1; i <= n; ++i)
        cmin(mi, f[i][i + n - 1]),
        cmax(mx, g[i][i + n - 1]);
    printf("%d\n%d\n", mi, mx);
}

int main() {
    work();
    return 0;
}