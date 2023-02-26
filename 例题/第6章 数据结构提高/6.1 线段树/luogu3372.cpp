#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

struct t
{
    int l, r;
    ll s;
    ll f;
} tree[4 * N];
ll a[N];
int n, m, opt;

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
    tree[x].s = tree[x * 2].s + tree[x * 2 + 1].s;
}

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

void change(int x, int l, int r, ll val)
{
    if (l <= tree[x].l && r >= tree[x].r)
    {
        tree[x].s += val * (tree[x].r - tree[x].l + 1);
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

ll ask(int x, int l, int r)
{
    if (l <= tree[x].l && r >= tree[x].r)
        return tree[x].s;
    lazy(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    ll ans = 0;
    if (l <= mid)
        ans += ask(x * 2, l, r);
    if (r > mid)
        ans += ask(x * 2 + 1, l, r);
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int x, y;
        ll val;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
        {
            scanf("%lld", &val);
            change(1, x, y, val);
        }
        else
        {
            printf("%lld\n", ask(1, x, y));
        }
    }
    return 0;
}