void change(int x, int pos, int val)
{
    if (tree[x].l == tree[x].r)
    {
        tree[x].s = val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
        change(x * 2, pos, val);
    else
        change(x * 2 + 1, pos, val);

    tree[x].s = min(tree[x * 2].s, tree[x * 2 + 1].s);
}
