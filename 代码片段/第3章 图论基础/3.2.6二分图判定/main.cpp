const int N = 1e5 + 10, M = 2 * N;
int head[N], e[M], Next[M], idx;
int color[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b;
    Next[idx] = head[a];
    head[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c; // 记录颜色

    for (int i = head[u]; i != -1; i = Next[i])
    {
        int j = e[i];
        if (!color[j]) // 如果没染过颜色
        {
            // dfs深搜 染色 1 或者 2
            // 如果不可以将j成功染色
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
            return false; // 如果染过颜色且和c相同
    }

    return true;
}

int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof(head));

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    // 遍历判断所有点，染色
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i]) // 如果这个点未染色
        {
            if (!dfs(i, 1)) // dfs过程中要是返回false——有矛盾发生，不是二分图
            {
                flag = false;
                break;
            }
            // 不发生矛盾则继续搜
        }
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}