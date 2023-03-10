#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(3e2);
const int inf = 0x3f3f3f3f;

int n, m;
int a[M + 5];
vector<int> g[M + 5];
int f[M + 5][M + 5];
int backup[M + 5];

void dfs(int u) {
    f[u][0] = 0, f[u][1] = a[u];
    for (const int &v: g[u]) {
        dfs(v);
        memcpy(backup, f[u], sizeof f[u]);
        for (int i = 1; i <= m; i++)
            for (int j = 1; i + j <= m; j++) cmax(f[u][i + j], backup[i] + f[v][j]);
    }
}

void work() {
    scanf("%d %d", &n, &m); ++m;
    for (int i = 1, fa; i <= n; i++) {
        scanf("%d %d", &fa, &a[i]);
        g[fa].push_back(i);
    }
    memset(f, -inf, sizeof f);
    dfs(0);
    printf("%d\n", f[0][m]);
}

int main() {
    work();
    return 0;
}