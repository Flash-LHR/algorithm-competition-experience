#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 5e4 + 10;
;

int n, m, unit, col[N], be[N];
ll sum[N], ans;

struct Mo
{
    int l, r, id;
    ll A, B;
};
Mo q[N];

ll S(ll x)
{
    return x * x;
}

ll gcd(ll a, ll b)
{
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}

int cmp1(Mo a, Mo b)
{
    return be[a.l] == be[b.l] ? a.r < b.r : a.l < b.l;
}

int cmp(Mo a, Mo b)
{
    return a.id < b.id;
}

void revise(int x, int add)
{
    ans -= S(sum[col[x]]);
    sum[col[x]] += add;
    ans += S(sum[col[x]]);
}

int main()
{
    scanf("%d%d", &n, &m);
    unit = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &col[i]);
        be[i] = i / unit + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp1);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (l < q[i].l)
        {
            revise(l, -1);
            l++;
        }
        while (l > q[i].l)
        {
            revise(l - 1, 1);
            l--;
        }
        while (r < q[i].r)
        {
            revise(r + 1, 1);
            r++;
        }
        while (r > q[i].r)
        {
            revise(r, -1);
            r--;
        }
        if (q[i].l == q[i].r)
        {
            q[i].A = 0;
            q[i].B = 1;
            continue;
        }
        q[i].A = ans - (q[i].r - q[i].l + 1);
        q[i].B = 1LL * (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
        ll g = gcd(q[i].A, q[i].B);
        q[i].A /= g;
        q[i].B /= g;
    }
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        printf("%lld/%lld\n", q[i].A, q[i].B);
    }
    return 0;
}