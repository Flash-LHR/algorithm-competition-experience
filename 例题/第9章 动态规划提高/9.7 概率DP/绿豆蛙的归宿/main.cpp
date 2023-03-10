#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int M = int(1e5);
const db eps = 1e-6;

inline int sign(db a) {return a < -eps ? -1 : a > eps;}
inline int cmp(db a, db b) {return sign(a - b);}

db f[M + 5];
vector<pair<int, int>> g[M + 5];

db dfs(int u) {
    if (cmp(f[u], -1.) != 0) return f[u];
    f[u] = 0.;
    for (const auto &[v, w]: g[u]) f[u] += dfs(v) + w;
    return f[u] = f[u] / g[u].size();
}

void work() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a ,&b, &c);
        g[a].push_back({b, c});
    }
    for (int i = 1; i < n; i++) f[i] = -1.;
    f[n] = 0.;
    printf("%.2f\n", dfs(1));
}

int main() {
    work();
    return 0;
}