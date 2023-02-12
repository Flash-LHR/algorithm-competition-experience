#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int M = (int)2e4;
const int inf = 0x3f3f3f3f;

int n;
int sz[M + 5];
vector<int> g[M + 5];
int mi, id;

void dfs(int u, int fa) {
    sz[u] = 1;
    int mx = 0;
    for (size_t i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx = max(mx, sz[v]);
    }
    mx = max(mx, n - sz[u]);
    if (mx < mi || (mx == mi && u < id)) {
        mi = mx;
        id = u;
    }
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    mi = inf;
    dfs(1, 0);
    printf("%d %d\n", id, mi);
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}