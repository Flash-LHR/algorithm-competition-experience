// Data
const ll N = 510;
ll n, m, e[N][N];

// KM
ll mat[N], d[N], va[N], vb[N], ak[N], bk[N];
ll Dfs(ll u)
{
    va[u] = 1;
    for (ll v = 1; v <= n; v++)
        if (!va[v])
        {
            if (ak[u] + bk[v] - e[u][v] == 0)
            {
                vb[v] = 1;
                if (!mat[v] || Dfs(mat[v]))
                    return mat[v] = u, 1;
            }
            else
                d[v] = min(d[v], ak[u] + bk[v] - e[u][v]);
        }
    return 0;
}

ll KM()
{
    fill(ak + 1, ak + n + 1, -INF);
    for (ll u = 1; u <= n; u++)
        for (ll v = 1; v <= n; v++)
            ak[u] = max(ak[u], e[u][v]);
    for (ll u = 1; u <= n; u++)
    {
        while (true)
        {
            memset(va, 0, sizeof(va));
            memset(vb, 0, sizeof(vb));
            memset(d, 0x3f, sizeof(d));
            if (Dfs(u))
                break;
            ll c = INF;
            for (ll v = 1; v <= n; v++)
                if (!vb[v])
                    c = min(c, d[v]);
            for (ll v = 1; v <= n; v++)
                if (va[v])
                    ak[v] -= c;
            for (ll v = 1; v <= n; v++)
                if (vb[v])
                    bk[v] += c;
        }
    }
    ll res = 0;
    for (ll v = 1; v <= n; v++)
        res += e[mat[v]][v];
    return res;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll u = 1; u <= n; u++)
        for (ll v = 1; v <= n; v++)
            e[u][v] = -INF;
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        e[u][v] = max(e[u][v], w);
    }
    printf("%lld\n", KM());
    for (ll u = 1; u <= n; u++)
        printf("%lld ", mat[u]);
    puts("");
    return 0;
}