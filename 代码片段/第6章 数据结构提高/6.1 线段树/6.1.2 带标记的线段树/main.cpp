void lazy(int x)
{
    if (tree[x].f)
    {
        tree[x * 2].s += tree[x].f * (tree[x * 2].r - tree[x * 2].l + 1);
        tree[x * 2 + 1].s += tree[x].f * (tree[x * 2 + 1].r - tree[x * 2 + 1].l + 1);
        tree[x * 2].f += tree[x].f;
        tree[x * 2 + 1].f += tree[x].f;
        tree[x].f = 0;
    }
}

void change(int x, int l, int r, int val)
{
    if (l <= tree[x].l && r >= tree[x].r)
    {
        tree[x].s += (long long)val * (tree[x].r - tree[x].l + 1);
        tree[x].f += val;
        return;
    }
    lazy(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (l <= mid)
        change(x * 2, l, r, val);
    if (r > mid)
        change(x * 2 + 1, l, r, val);
    tree[x].s = tree[x * 2].s + tree[x * 2 + 1].s;
}

long long ask(int x, int l, int r)
{
    if (l <= tree[x].l && r >= tree[x].r)
        return tree[x].s;
    lazy(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += ask(x * 2, l, r);
    if (r > mid)
        ans += ask(x * 2 + 1, l, r);
    return ans;
}