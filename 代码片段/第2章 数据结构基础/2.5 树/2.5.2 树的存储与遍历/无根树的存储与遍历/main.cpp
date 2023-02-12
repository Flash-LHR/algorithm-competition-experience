vector<int> g[M + 5];

void dfs(int u, int fa) {
    for (const int &v: g[u]) if (v != fa) {
        dfs(v, u);
    }
}

for (int i = 2, u, v; i <= n; i++) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
}
dfs(1, 0);