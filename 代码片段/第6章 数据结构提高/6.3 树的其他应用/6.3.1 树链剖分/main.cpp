void dfs(int x)
{
    size[x] = 1;
    d[x] = d[f[x]] + 1;
    for (int i = head[x]; i; i = edge[i].next)
    {
        if (edge[i].v != f[x])
        {
            f[edge[i].v] = x;
            dfs(edge[i].v);
            size[x] += size[edge[i].v];
            if (size[edge[i].v] > size[son[x]])
            {
                son[x] = edge[i].v;
            }
        }
    }
}

void dfs2(int x, int tp)
{
    top[x] = tp;
    if (son[x])
        dfs2(son[x], tp);
    for (int i = head[x]; i; i = edge[i].next)
    {
        if (edge[i].v != f[x] && edge[i].v != son[x])
        {
            dfs2(edge[i].v, edge[i].v);
        }
    }
}
