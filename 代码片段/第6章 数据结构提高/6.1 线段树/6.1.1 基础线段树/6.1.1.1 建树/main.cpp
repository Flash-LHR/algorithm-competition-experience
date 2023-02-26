struct t
{
  int l, r;
  int s;
} tree[4 * N];

void build(int x, int l, int r)
{
  tree[x].l = l;
  tree[x].r = r;
  if (l == r)
  {
    tree[x].s = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
  tree[x].s = min(tree[x * 2].s, tree[x * 2 + 1].s);
}