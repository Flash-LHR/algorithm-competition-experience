#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n, num, p, y;
const int N = 2e5 + 10, INF = 1e9 + 10;
int d[N];

struct node
{
    int l, r;
    int num;
} tree[N * 4 + 10];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        tree[x].num = d[l] - d[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    tree[x].num = max(tree[x * 2].num, tree[x * 2 + 1].num);
}

void modify(int x, int pos)
{
    if (tree[x].l == tree[x].r && tree[x].l == pos)
    {
        tree[x].num = d[pos] - d[pos - 1];
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (pos > tree[x].r || pos < tree[x].l)
        return;
    if (pos <= mid)
        modify(x * 2, pos);
    else
        modify(x * 2 + 1, pos);
    tree[x].num = max(tree[x * 2].num, tree[x * 2 + 1].num);
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(d, 0, sizeof d);
        d[0] = INF;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &p, &y);
            d[p] = y;
            if (p != 1)
                modify(1, p);
            if (p + 1 <= n)
                modify(1, p + 1);
            int ans = tree[1].num;
            printf("%.2f\n", (double)ans);
        }
    }
    return 0;
}