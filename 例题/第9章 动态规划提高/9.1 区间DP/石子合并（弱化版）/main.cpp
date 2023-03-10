#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

const int M = int(3e2);
const int inf = 0x3f3f3f3f;

int s[M + 5];
int f[M + 5][M + 5];

void work() {
    int n; scanf("%d", &n);
    memset(f, inf, sizeof f);
    for (int i = 1; i <= n; ++i) scanf("%d", &s[i]), s[i] += s[i - 1], f[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
                cmin(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    }
    printf("%d\n", f[1][n]);
}

int main() {
    work();
    return 0;
}