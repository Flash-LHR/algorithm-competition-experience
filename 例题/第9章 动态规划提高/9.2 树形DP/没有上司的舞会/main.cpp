#include <bits/stdc++.h>
using namespace std;

const int M = int(6e3);
const int inf = 0x3f3f3f3f;

int r[M + 5];
bool in[M + 5];
vector<int> g[M + 5];
int f[M + 5][2];

void dfs(int u) {
    f[u][0] = 0, f[u][1] = r[u];
    for (const int &v: g[u]) {
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

void work() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for (int i = 2, u, fa; i <= n; i++) {
        scanf("%d %d", &u, &fa);
        g[fa].push_back(u);
        in[u] = true;
    }
    int rt = -1;
    for (int i = 1; i <= n; i++) if (!in[i]) rt = i;
    dfs(rt);
    printf("%d\n", max(f[rt][0], f[rt][1]));
}

int main() {
    work();
    return 0;
}