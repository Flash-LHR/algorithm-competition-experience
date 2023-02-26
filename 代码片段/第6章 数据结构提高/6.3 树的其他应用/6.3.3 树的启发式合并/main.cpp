void dfs2(int u, int fa, int del)
{
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int j = edge[i].v;
        if (j == son[u] || j == fa)
            continue;
        dfs2(j, u, 1);
    }

    if (son[u])
        dfs2(son[u], u, 0);

    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int j = edge[i].v;
        if (j == son[u] || j == fa)
            continue;
        for (int k = l[j]; k <= r[j]; k++)
            update(rw[k], 1);
    }
    update(u, 1);
    ans[u] = sum;

    if (del)
    {
        for (int k = l[u]; k <= r[u]; k++)
            update(rw[k], -1);
        maxv = sum = 0;
    }
}