#include <bits/stdc++.h>
using namespace std;

int read()
{
    int re = 0, k = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            k = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        re = re * 10 + ch - 48;
        ch = getchar();
    }
    return re * k;
}

void write(int x)
{
    if (x < 0)
        return putchar('-'), write(-x), void();
    if (x < 10)
        return putchar(x + 48), void();
    return write(x / 10), write(x % 10), void();
}

const int BB = 351;
const int N = 1e5 + 10;
int h[N], l[N], head[N], tot, d[N], fa[N], top[N], n;
int a[N], sz[N], son[N], f[405][N], p[405], ls, t[N], c[N], g[N];
int fs[2 * N], tt;
bool vis[N];
int vis2[N], vis1[N];
int lans;

struct ss
{
    int node, nxt;
} e[N];

void add(int u, int v)
{
    e[++tot].nxt = head[u];
    e[tot].node = v;
    head[u] = tot;
}

void dfs(int x, int ffa, int dp)
{
    fa[x] = ffa;
    d[x] = dp;
    sz[x] = 1;

    int maxsz = -1;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int k = e[i].node;
        if (k == ffa)
            continue;
        if (!vis[k])
            g[k] = g[x];
        else
            g[k] = k;
        dfs(k, x, dp + 1);
        sz[x] += sz[k];
        if (maxsz < sz[k])
            maxsz = sz[k], son[x] = k;
    }
}

void ddfs(int x, int tt)
{
    top[x] = tt;
    l[x] = h[a[x]];
    if (!son[x])
        return;
    h[a[x]] = x;
    ddfs(son[x], tt);
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int k = e[i].node;
        if (fa[x] == k || son[x] == k)
            continue;
        ddfs(k, k);
    }
    h[a[x]] = l[x];
}

int lca(int x, int y) // 树剖LCA
{
    while (top[x] != top[y])
    {
        if (d[top[x]] < d[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    if (d[x] > d[y])
        swap(x, y);
    return x;
}

void dp(int x, int fa, int *ff, int *s, int ls, int ans)
{
    if (!x)
        return;
    s[++ls] = a[x];
    if (t[a[x]] && !vis2[a[x]])
        ans++;
    vis2[s[ls]]++;
    if (vis[x])
    {
        for (int i = 1; i <= ls; i++)
        {
            if (!t[s[i]])
                tt++;
            t[s[i]]++, vis2[s[i]]--;
        }
        ff[x] = tt;
    }
    else
        ff[x] = ans;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        if (e[i].node == fa)
            continue;
        if (vis[x])
            dp(e[i].node, x, ff, s + ls, 0, 0);
        else
            dp(e[i].node, x, ff, s, ls, ans);
    }
    if (vis[x])
    {
        for (int i = 1; i <= ls; i++)
        {
            t[s[i]]--;
            vis2[s[i]]++;
            if (!t[s[i]])
                tt--;
        }
    }
    vis2[s[ls]]--;
}

int sol(int u, int v, int typ)
{
    int lans = 0;
    int x = u, y = v, LCA = lca(u, v);
    while (x != LCA)
    {
        if (!vis1[a[x]])
            lans++;
        vis1[a[x]] = 1;
        x = fa[x];
    }
    while (y != LCA)
    {
        if (!typ || y != v)
        {
            if (!vis1[a[y]])
                lans++;
            vis1[a[y]] = 1;
        }
        y = fa[y];
    }
    if (!vis1[a[LCA]] && (!typ || LCA != v))
        lans++;
    while (u != LCA)
    {
        vis1[a[u]] = 0;
        u = fa[u];
    }
    while (v != LCA)
    {
        vis1[a[v]] = 0;
        v = fa[v];
    }
    return lans;
}

int b[N], cnt, q;

void solve1(int u, int v)
{
    int x = u, y = v, LCA = lca(u, v);
    while (x != LCA)
    {
        if (!vis1[a[x]])
            lans++;
        vis1[a[x]] = 1;
        x = fa[x];
    }
    while (y != LCA)
    {
        if (!vis1[a[y]])
            lans++;
        vis1[a[y]] = 1;
        y = fa[y];
    }
    if (!vis1[a[LCA]])
        lans++;
    while (u != LCA)
    {
        vis1[a[u]] = 0;
        u = fa[u];
    }
    while (v != LCA)
    {
        vis1[a[v]] = 0;
        v = fa[v];
    }
    write(lans);
    puts("");
}

int main()
{
    n = read();
    q = read();
    for (int i = 1; i <= n; i++)
    {
        b[++cnt] = a[i] = read();
        c[i] = i;
    }
    for (int i = 1, u, v; i < n; i++)
    {
        u = read();
        v = read();
        add(u, v);
        add(v, u);
    }
    srand(time(0));
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    random_shuffle(c + 2, c + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i <= BB)
            p[i] = c[i], vis[c[i]] = 1;
        a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    }
    g[1] = 1;
    dfs(1, 0, 1);
    ddfs(1, 1);
    for (int i = 1; i <= BB; i++)
        dp(p[i], 0, f[i], fs, 0, 0);
    lans = 0;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    for (int i = 1, u, v; i <= q; i++)
    {
        u = read() ^ lans;
        v = read();
        if (g[u] == g[v]) // 零散块
        {
            lans = 0;
            solve1(u, v);
            continue;
        }
        int LCA = lca(u, v);
        if (d[g[u]] < d[LCA] || d[g[v]] < d[LCA])
        {
            if (d[g[u]] < d[LCA])
                swap(u, v);
            int x = u, y = v, z = u, A = 0, B = 0, C = 0, AB = 0, BC = 0, AC = 0, ABC = 0, xx = u, yy = v, ty;
            while (!vis[x] && x != LCA)
            {
                if (!vis1[a[x]])
                    A++;
                vis1[a[x]] = x;
                x = fa[x];
            }
            while (!vis[y] && y != LCA)
            {
                if (!vis2[a[y]])
                {
                    B++;
                    if (vis1[a[y]])
                    {
                        AB++;
                    }
                }
                vis2[a[y]] = y;
                y = fa[y];
            }
            while (d[g[fa[g[z]]]] > d[LCA])
                z = fa[g[z]];
            ty = z = g[z];
            z = fa[z];
            int zz = z;
            while (!vis[z] && z != LCA)
            {
                if (!vis2[a[z]])
                {
                    B++;
                    if (vis1[a[z]])
                    {
                        AB++;
                    }
                }
                vis2[a[z]] = z;
                z = fa[z];
            }
            if (!vis2[a[LCA]])
            {
                B++;
                if (vis1[a[LCA]])
                    AB++;
            }
            vis2[a[LCA]] = LCA;
            while (!vis[yy] && yy != LCA)
            {
                if (vis2[a[yy]] && vis1[a[yy]])
                {
                    if ((d[l[vis1[a[yy]]]] >= d[ty] && d[l[vis1[a[yy]]]] <= d[x]))
                        ABC++;
                }
                vis2[a[yy]] = 0;
                yy = fa[yy];
            }
            while (!vis[zz] && zz != LCA)
            {
                if (vis2[a[zz]] && vis1[a[zz]])
                {
                    if ((d[l[vis1[a[zz]]]] >= d[ty] && d[l[vis1[a[zz]]]] <= d[x]))
                        ABC++;
                }
                vis2[a[zz]] = 0;
                zz = fa[zz];
            }
            if (vis2[a[LCA]])
            {
                if (vis1[a[LCA]])
                    if ((d[l[vis1[a[LCA]]]] >= d[ty] && d[l[vis1[a[LCA]]]] <= d[x]))
                        ABC++;
            }
            vis2[a[LCA]] = 0;
            while (!vis[xx] && xx != LCA)
            {
                vis1[a[xx]] = 0;
                xx = fa[xx];
            }
            for (int j = 1; j <= BB; j++)
                if (p[j] == x)
                {
                    x = j;
                    break;
                }
            for (int j = 1; j <= BB; j++)
                if (p[j] == ty)
                {
                    ty = j;
                    break;
                }
            C = f[x][p[ty]];
            if (!vis[v])
                BC = f[x][v];
            if (!vis[u])
                AC = f[ty][u];
            lans = A + B + C - AB - BC - AC + ABC;
            write(lans);
            puts("");
            continue;
        }

        int x = u, y = v, A = 0, B = 0, C = 0, AB = 0, BC = 0, AC = 0, ABC = 0, xx = u, yy = v;
        while (!vis[x] && x != LCA)
        {
            if (!vis1[a[x]])
                A++;
            vis1[a[x]] = x;
            x = fa[x];
        }
        while (!vis[y] && y != LCA)
        {
            if (!vis2[a[y]])
            {
                B++;
                if (vis1[a[y]])
                {
                    AB++;
                }
            }
            vis2[a[y]] = y;
            y = fa[y];
        }
        while (!vis[yy] && yy != LCA)
        {
            if (vis2[a[yy]] && vis1[a[yy]])
            {
                if (((d[l[vis1[a[yy]]]] >= d[LCA]) && (d[l[vis1[a[yy]]]] <= d[x])) ||
                    ((d[l[vis2[a[yy]]]] >= d[LCA]) && (d[l[vis2[a[yy]]]] <= d[y])))
                    ABC++;
            }
            vis2[a[yy]] = 0;
            yy = fa[yy];
        }
        while (!vis[xx] && xx != LCA)
        {
            vis1[a[xx]] = 0;
            xx = fa[xx];
        }
        for (int j = 1; j <= BB; j++)
            if (p[j] == x)
            {
                x = j;
                break;
            }
        for (int j = 1; j <= BB; j++)
            if (p[j] == y)
            {
                y = j;
                break;
            }
        C = f[x][p[y]];
        if (!vis[v])
            BC = f[x][v];
        if (!vis[u])
            AC = f[y][u];
        lans = A + B + C - AB - BC - AC + ABC;
        write(lans);
        puts("");
    }
    return 0;
}