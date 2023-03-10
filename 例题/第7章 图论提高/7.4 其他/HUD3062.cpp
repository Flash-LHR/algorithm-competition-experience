#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3000;
const int M = 4e6 + 100;
int Index, instack[N], DFN[N], LOW[N];
int tot, color[N];
int numedge, head[N];

struct Edge
{
    int nxt, to;
} edge[M];

int sta[N], top;
int n, m;

void add(int x, int y)
{
    edge[++numedge].to = y;
    edge[numedge].nxt = head[x];
    head[x] = numedge;
}

void tarjan(int x)
{
    sta[++top] = x;
    instack[x] = 1;
    DFN[x] = LOW[x] = ++Index;
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (!DFN[v])
        {
            tarjan(v);
            LOW[x] = min(LOW[x], LOW[v]);
        }
        else if (instack[v])
            LOW[x] = min(LOW[x], DFN[v]);
    }
    if (DFN[x] == LOW[x])
    {
        tot++;
        do
        {
            color[sta[top]] = tot;
            instack[sta[top]] = 0;
        } while (sta[top--] != x);
    }
}

bool solve()
{
    for (int i = 0; i < 2 * n; i++)
        if (!DFN[i])
            tarjan(i);
    for (int i = 0; i < 2 * n; i += 2)
        if (color[i] == color[i + 1])
            return 0;
    return 1;
}

void init()
{
    top = 0;
    tot = 0;
    Index = 0;
    numedge = 0;
    memset(sta, 0, sizeof(sta));
    memset(DFN, 0, sizeof(DFN));
    memset(instack, 0, sizeof(instack));
    memset(LOW, 0, sizeof(LOW));
    memset(color, 0, sizeof(color));
    memset(head, 0, sizeof(head));
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            int a1, a2, c1, c2;
            scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
            add(2 * a1 + c1, 2 * a2 + 1 - c2);
            add(2 * a2 + c2, 2 * a1 + 1 - c1);
        }
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
