#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 505;
const int M = 505;

int n, m, res;
vector<int> edge[N];
bool vis[M];
int pb[M];

bool dfs(int u)
{
    for (int i = 0; i < edge[u].size(); ++i)
    {
        int v = edge[u][i];
        if (vis[v])
            continue;
        vis[v] = true;
        if (pb[v] == -1 || dfs(pb[v]))
        {
            pb[v] = u;
            return true;
        }
    }
    return false;
}

void solve()
{
    res = 0;
    memset(pb, -1, sizeof(pb));
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
        {
            ++res;
        }
    }
}

int main()
{
    int e, u, v;
    scanf("%d%d%d", &n, &m, &e);
    while (e--)
    {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
    }
    solve();
    printf("%d\n", res);
    return 0;
}
