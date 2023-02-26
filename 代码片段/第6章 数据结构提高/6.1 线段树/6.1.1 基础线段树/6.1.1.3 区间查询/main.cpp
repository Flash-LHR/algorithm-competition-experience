int ask(int x, int l, int r)
{
    if (l <= tree[x].l && tree[x].r <= r)
        return tree[x].s;
    int mid = (tree[x].l + tree[x].r) >> 1;
    int ans = INF;
    if (l <= mid)
        ans = min(ans, ask(x * 2, l, r));
    if (r > mid)
        ans = min(ans,ask(x * 2 + 1,l,r);
    return ans;
}
