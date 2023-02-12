#include <bits/stdc++.h>
using namespace std;

const int M = (int)5e5;
const int N = 18;

int d[M + 5];
int f[M + 5][N + 1];
vector<int> g[M + 5];

void dfs(int u, int fa) {
    for (const int &v: g[u]) if (v != fa) {
        d[v] = d[u] + 1;
        f[v][0] = u;
        for (int i = 1; i <= N; i++) f[v][i] = f[f[v][i - 1]][i - 1];
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = N; i >= 0; i--) if (d[f[x][i]] >= d[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = N; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

void work() {
    int n, m, s; scanf("%d %d %d", &n, &m, &s);
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    d[s] = 1; dfs(s, 0);
    for (int i = 1, a, b; i <= m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
}

int main() {
    work();
    return 0;
}