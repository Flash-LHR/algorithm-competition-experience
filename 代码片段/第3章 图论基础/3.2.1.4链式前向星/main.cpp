struct E
{
    int to, w, next;
} edge[10010];

int n, m, cnt;
bool vis[10010];
int head[10010];

void add(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool find_edge(int u, int v)
{
    for (int i = head[u]; ~i; i = edge[i].next)
    { // ~i 表示 i != -1
        if (edge[i].to == v)
        {
            return true;
        }
    }
    return false;
}

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next)
        dfs(edge[i].to);
}

int main()
{
    cin >> n >> m;

    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));

    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    return 0;
}
