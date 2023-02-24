#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e3;

int n;
int a[M + 5][M + 5];
int f[M + 5][M + 5];

int dfs(int x, int y) {
    if (~f[x][y]) return f[x][y];
    if (x == n) return f[x][y] = a[x][y];
    return f[x][y] = a[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1));
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]), f[i][j] = -1;
    printf("%d\n", dfs(1, 1));
}

int main() {
    work();
    return 0;
}