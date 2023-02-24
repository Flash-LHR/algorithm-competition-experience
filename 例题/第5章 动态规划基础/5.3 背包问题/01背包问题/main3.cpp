#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e3;
const int inf = 0x3f3f3f3f;

int f[2][M + 5];

void work() {
    int n, V; scanf("%d %d", &n, &V);
    memset(f, -inf, sizeof f);
    f[0][0] = 0;
    for (int i = 1, u, v, w; i <= n; i++) {
        u = i & 1;
        scanf("%d %d", &v, &w);
        for (int j = 0; j <= V; j++) {
            f[u][j] = f[u ^ 1][j];
            if (j >= v) f[u][j] = max(f[u][j], f[u ^ 1][j - v] + w);
        }
    }
    printf("%d\n", *max_element(f[n & 1], f[n & 1] + V + 1));
}

int main() {
    work();
    return 0;
}