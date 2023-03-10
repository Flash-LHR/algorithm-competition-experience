#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(1e2);
const int inf = 0x3f3f3f3f;

char op[M + 5];
int a[M + 5];
int f[M + 5][M + 5][2];

void work() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        getchar();
        scanf("%c %d", &op[i - 1], &a[i]);
        op[i - 1 + n] = op[i - 1];
        a[i + n] = a[i];
        f[i + n][i + n][0] = f[i + n][i + n][1] = f[i][i][0] = f[i][i][1] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 < 2 * n; l++) {
            int r = l + len - 1;
            f[l][r][0] = -inf, f[l][r][1] = inf;
            for (int k = l; k < r; k++) {
                auto fop = op[k] == 't' ? [](int a, int b) {return a + b;} : [](int a, int b) {return a * b;};
                for (int i = 0; i < 1<<2; i++)
                    cmax(f[l][r][0], fop(f[l][k][i>>1], f[k + 1][r][i&1])),
                    cmin(f[l][r][1], fop(f[l][k][i>>1], f[k + 1][r][i&1]));
            }
        }
    }
    int mx = -inf;
    for (int i = 1; i <= n; i++) cmax(mx, f[i][i + n - 1][0]);
    printf("%d\n", mx);
    for (int i = 1, flag = 0; i <= n; i++) {
        if (f[i][i + n - 1][0] == mx) {
            if (flag) printf(" ");
            flag = 1;
            printf("%d", i);
        }
    }
    printf("\n");
}

int main() {
    work();
    return 0;
}