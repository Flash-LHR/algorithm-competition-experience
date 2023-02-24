#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int mod = (int)1e9 + 7;

int f[M + 5][3][3];

void init() {
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) f[2][i][j] = 1;
    for (int i = 3; i <= M; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) if (!(l == j && j == k)) {
                    (f[i][j][k] += f[i - 1][l][j]) %= mod;
                }
            }
        }
    }
}

void work() {
    int n; scanf("%d", &n);
    if (n == 1) return printf("3\n"), void();
    ll ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) (ans += f[n][i][j]) %= mod;
    printf("%lld\n", ans);
}

int main() {
    init();
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}