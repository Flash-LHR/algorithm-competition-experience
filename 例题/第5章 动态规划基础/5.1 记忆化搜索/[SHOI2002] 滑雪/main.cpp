#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;

int n, m;
int a[M + 5][M + 5];
int f[M + 5][M + 5];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if (~f[x][y]) return f[x][y];
    f[x][y] = 1;
     for (int i = 0; i < 4; i++) {
        int vx = x + dx[i], vy = y + dy[i];
        if (vx < 1 || vx > n || vy < 1 || vy > m || a[x][y] <= a[vx][vy]) continue;
        f[x][y] = max(f[x][y], dfs(vx, vy) + 1);
     }
     return f[x][y];
}

void work() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), f[i][j] = -1;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mx = max(mx, dfs(i, j));
    printf("%d\n", mx);
}

int main() {
    work();
    return 0;
}