#include <cstdio>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], p;

struct node
{
    ll sum, l, r, mu, add;
} tree[N * 4];

void build(ll x, ll l, ll r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].mu = 1;
    if (l == r)
    {
        tree[x].sum = a[l] % p;
        return;
    }
    ll mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    tree[x].sum = (tree[x * 2].sum + tree[x * 2 + 1].sum) % p;
}

void lazy(ll x)
{
    tree[x * 2].sum = (ll)(tree[x].mu * tree[x * 2].sum + ((tree[x * 2].r - tree[x * 2].l + 1) * tree[x].add) % p) % p;
    tree[x * 2 + 1].sum = (ll)(tree[x].mu * tree[x * 2 + 1].sum + (tree[x].add * (tree[x * 2 + 1].r - tree[x * 2 + 1].l + 1)) % p) % p;

    tree[x * 2].mu = (ll)(tree[x * 2].mu * tree[x].mu) % p;
    tree[x * 2 + 1].mu = (ll)(tree[x * 2 + 1].mu * tree[x].mu) % p;

    tree[x * 2].add = (ll)(tree[x * 2].add * tree[x].mu + tree[x].add) % p;
    tree[x * 2 + 1].add = (ll)(tree[x * 2 + 1].add * tree[x].mu + tree[x].add) % p;

    tree[x].mu = 1, tree[x].add = 0;
}

void add(ll x, ll l, ll r, ll k)
{
    if (tree[x].l >= l && tree[x].r <= r)
    {
        tree[x].add = (tree[x].add + k) % p;
        tree[x].sum = (ll)(tree[x].sum + k * (tree[x].r - tree[x].l + 1)) % p;
        return;
    }

    lazy(x);
    tree[x].sum = (tree[x * 2].sum + tree[x * 2 + 1].sum) % p;
    ll mid = (tree[x].l + tree[x].r) / 2;
    if (l <= mid)
        add(x * 2, l, r, k);
    if (mid < r)
        add(x * 2 + 1, l, r, k);
    tree[x].sum = (tree[x * 2].sum + tree[x * 2 + 1].sum) % p;
}

void mu(ll x, ll l, ll r, ll k)
{
    if (tree[x].l >= l && tree[x].r <= r)
    {
        tree[x].add = (tree[x].add * k) % p;
        tree[x].mu = (tree[x].mu * k) % p;
        tree[x].sum = (tree[x].sum * k) % p;
        return;
    }

    lazy(x);
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    ll mid = (tree[x].l + tree[x].r) / 2;
    if (l <= mid)
        mu(x * 2, l, r, k);
    if (mid < r)
        mu(x * 2 + 1, l, r, k);
    tree[x].sum = (tree[x * 2].sum + tree[x * 2 + 1].sum) % p;
}

ll ask(ll x, ll l, ll r)
{
    if (tree[x].l >= l && tree[x].r <= r)
    {
        return tree[x].sum;
    }
    lazy(x);
    ll val = 0;
    ll mid = (tree[x].l + tree[x].r) / 2;
    if (l <= mid)
        val = (val + ask(x * 2, l, r)) % p;
    if (mid < r)
        val = (val + ask(x * 2 + 1, l, r)) % p;
    return val;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int ty;
        ll cn, cm, cw;
        scanf("%d", &ty);
        if (ty == 1)
        {
            scanf("%lld%lld%lld", &cn, &cm, &cw);
            mu(1, cn, cm, cw);
        }
        else if (ty == 2)
        {
            scanf("%lld%lld%lld", &cn, &cm, &cw);
            add(1, cn, cm, cw);
        }
        else
        {
            scanf("%lld%lld", &cn, &cm);
            printf("%lld\n", ask(1, cn, cm));
        }
    }
    return 0;
}