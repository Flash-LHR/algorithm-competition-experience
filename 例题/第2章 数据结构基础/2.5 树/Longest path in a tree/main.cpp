#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e4;

vector<int> g[M + 5];
int d[M + 5];

void dfs(int u, int fa) {
    for (const int &v: g[u]) if (v != fa) {
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

void work() {
    int n; scanf("%d", &n);
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    d[1] = 0; dfs(1, 0);
    int mx = -1, u, v;
    for (int i = 1; i <= n; i++) if (d[i] > mx) mx = d[i], u = i;
    d[u] = 0; dfs(u, 0);
    mx = -1;
    for (int i = 1; i <= n; i++) if (d[i] > mx) mx = d[i], v = i;
    printf("%d\n", mx);
}

int main() {
    work();
    return 0;
}