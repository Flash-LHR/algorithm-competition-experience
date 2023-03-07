bool dfs(int u)
{
    for (int i = 0; i < edge[u].size(); ++i)
    {
        int v = edge[u][i];
        if (vis[v])
            continue;
        visit[v] = true;
        if (pb[v] == -1 || dfs(pb[v]))
        {
            pb[v] = u;
            return true;
        }
    }
    return false;
}