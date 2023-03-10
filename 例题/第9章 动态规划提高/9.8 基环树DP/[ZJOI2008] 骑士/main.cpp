#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T &n)
{
    n = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {n = n * 10 + ch - '0'; ch = getchar();}
    if (f == -1) n = -n;
}

template <typename T, typename... A>
inline void scan(T &n, A&... a)
{
    scan(n), scan(a...);
}

typedef long long ll;

const int M = int(1e6);

int cnt, head[M + 5];
struct edge {
    int v, nx;
} edge[M * 2 + 5];

int n, a[M + 5];
int fa[M + 5];
bool vis[M + 5];
bool used[M + 5];
ll f[M + 5][2];
int path[M + 5], m;

void add(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].nx = head[u];
    head[u] = cnt++;
}

void dfs(int u, int fa) {
    f[u][0] = 0, f[u][1] = a[u];
    vis[u] = 1, used[u] = 1, path[++m] = u;
    for (int i = head[u], v; ~i; i = edge[i].nx) {
        v = edge[i].v;
        if (used[v]) continue;
        dfs(v, u);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

ll cal(int rt) {
    for (int i = 1; i <= m; i++) used[path[i]] = 0;
    m = 0;
    dfs(rt, 0);
    return f[rt][0];
}

void work() {
    scan(n);
    memset(head, -1, sizeof(head[0]) * (n + 1));
    for (int i = 1; i <= n; i++) {
        scan(a[i], fa[i]);
        add(fa[i], i);
        add(i, fa[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int u1 = i, u2 = i;
        vis[u2] = 1;
        while (!vis[fa[u2]]) u1 = u2, vis[u2 = fa[u2]] = 1;
        ans += max(cal(u1), cal(u2));
    }
    printf("%lld\n", ans);
}

int main() {
    work();
    return 0;
}