int n, m;
struct node
{
    int u;
    int v;
    int w;
} e[maxn];

int fa[maxn], cnt, sum, num;

void add(int x, int y, int w)
{
    e[++cnt].u = x;
    e[cnt].v = y;
    e[cnt].w = w;
}

bool cmp(node x, node y)
{
    return x.w < y.w;
}

int find(int x)
{
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); // 路径压缩
}

/*
int find(int x)
{
    if(fa[x] == x) return x;
    else
    {
         fa[x] = find(fa[x]);//路径压缩
         return fa[x];
        }
}
*/

void kruskal()
{
    for (int i = 1; i <= cnt; i++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (x == y)
            continue;
        fa[x] = y;
        sum += e[i].w;
        if (++num == n - 1)
            break; // 如果构成了一颗树
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
    }
    std::sort(e + 1, e + 1 + cnt, cmp);
    kruskal();
    printf("%d", sum);
    return 0;
}
