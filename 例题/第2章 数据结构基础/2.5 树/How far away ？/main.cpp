#include <bits/stdc++.h>
using namespace std;

const int M = (int)4e4;
const int N = 15;

int d[M + 5], dis[M + 5];
int f[M + 5][N + 1];
vector<pair<int, int>> g[M + 5];

void dfs(int u, int fa) {
    for (const auto p: g[u]) {
        int v = p.first, w = p.second;
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dis[v] = dis[u] + w;
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
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2, u, v, w; i <= n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w}), g[v].push_back({u, w});
    }
    d[1] = 1; dfs(1, 0);
    for (int i = 1, a, b; i <= m; i++) {
        scanf("%d %d", &a, &b);
        int c = lca(a, b);
        printf("%d\n", dis[a] + dis[b] - 2 * dis[c]);
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}