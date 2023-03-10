struct edge
{
    int v, w, next;
} e[maxm << 1];
int head[maxn], dis[maxn], cnt, n, m, tot, now = 1, ans;
bool vis[maxn];

void add(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
}

int prim()
{
    for (int i = 2; i <= n; ++i)
    {
        dis[i] = inf;
    }
    for (int i = head[1]; i; i = e[i].next)
    {
        dis[e[i].v] = min(dis[e[i].v], e[i].w);
    }
    while (++tot < n)
    {
        int minn = inf;
        vis[now] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && minn > dis[i])
            {
                minn = dis[i];
                now = i;
            }
        }
        ans += minn;

        for (int i = head[now]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > e[i].w && !vis[v])
            {
                dis[v] = e[i].w;
            }
        }
    }
    return ans;
}

int main()
{
    init();
    printf("%d", prim());
    return 0;
}
