#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = int(2e5);
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll f[M + 5];
ll h[M + 5];
vector<pair<int, int>> g[M + 5];

void dfs1(int u, int fa) {
    f[u] = 0;
    bool leaf = true;
    for (const auto &[v, w]: g[u]) if (v != fa) {
        dfs1(v, u);
        leaf = false;
        f[u] += min((ll)w, f[v]);
    }
    if (leaf) f[u] = linf;
}

void dfs2(int u, int fa) {
    for (const auto &[v, w]: g[u]) if (v != fa) {
        h[v] = (f[v] == linf ? 0 : f[v]) + min((ll)w, h[u] - min((ll)w, f[v]));
        dfs2(v, u);
    }
}

void work() {
    int n; scanf("%d", &n);
    if (n == 1) return printf("0\n"), void();
    else if (n == 2) {
        int w; scanf("%*d %*d %d", &w);
        return printf("%d\n", w), void();
    }
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2, u, v, w; i <= n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w}), g[v].push_back({u, w});
    }
    int rt = -1;
    for (int i = 1; i <= n; i++) if (g[i].size() > 1) {rt = i; break;}
    dfs1(rt, 0);
    h[rt] = f[rt]; dfs2(rt, 0);
    printf("%lld\n", *max_element(h + 1, h + n + 1));
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}