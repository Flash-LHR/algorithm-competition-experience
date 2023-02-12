#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int N = (int)16;

int lg[M + 5];
int f[M + 5][N + 1];

void init() {
    lg[1] = 0;
    for (int i = 2; i <= M; i++) lg[i] = lg[i>>1] + 1;
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return max(f[l][k], f[r - (1<<k) + 1][k]);
}

void work() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i + (1<<j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1<<(j-1))][j - 1]);
    for (int i = 1, l, r; i <= m; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    }
}

int main() {
    init();
    work();
    return 0;
}