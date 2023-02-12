int dfn[M + 5], m; //  dfs序及其长度

void dfs(int u) {
    dfn[++m] = u;
    for (const int &v: g[u]) {
        dfs(v);
    }
    dfn[++m] = u;
}