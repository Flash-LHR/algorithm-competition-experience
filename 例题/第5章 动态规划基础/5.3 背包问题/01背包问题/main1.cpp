#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e3;

int f[M + 5][M + 5];

void work() {
    int n, V; scanf("%d %d", &n, &V);
    for (int i = 1, v, w; i <= n; i++) {
        scanf("%d %d", &v, &w);
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v) f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
        }
    }
    printf("%d\n", f[n][V]);
}

int main() {
    work();
    return 0;
}