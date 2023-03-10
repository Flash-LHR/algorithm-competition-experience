#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
struct edge
{
    int to, next;
} e[N];
int head[N], cnt;
int fa[N];
bool vis[N];
int ans[N];
struct node
{
    int v, id;
};
vector<node> ask[N];

void add(int u, int v)
{
    e[++cnt] = (edge){v, head[u]};
    head[u] = cnt;
}

int get(int x)
{
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void dfs(int u, int f)
{
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != f)
            dfs(e[i].to, u), fa[e[i].to] = u;
    int len = ask[u].size();
    for (int i = 0; i < len; i++)
        if (vis[ask[u][i].v])
            ans[ask[u][i].id] = get(ask[u][i].v);
    vis[u] = 1;
}

int main()
{
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= 500000; i++)
        fa[i] = i;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ask[u].push_back((node){v, i});
        ask[v].push_back((node){u, i});
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}