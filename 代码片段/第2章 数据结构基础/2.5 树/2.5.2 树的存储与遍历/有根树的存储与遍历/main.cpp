vector<int> g[M + 5];

void dfs(int u) {
    for (const int &v: g[u]) {
        dfs(v);
    }
}

for (int i = 2, fa; i <= n; i++) {
    scanf("%d %d", &fa, &i);
    g[fa].push_back(i);
}
dfs(1);