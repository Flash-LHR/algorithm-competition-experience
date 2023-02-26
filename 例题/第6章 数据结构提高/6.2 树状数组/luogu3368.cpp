#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;
int t[N << 2], a[N];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

int getsum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += t[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int x, int dlt)
{
    while (x <= n)
    {
        t[x] += dlt;
        x += lowbit(x);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        update(i, a[i] - a[i - 1]);
    }
    int opt, x, l, r;
    while (m--)
    {
        scanf("%d", &opt);
        if (opt == 2)
        {
            scanf("%d", &x);
            printf("%d\n", getsum(x));
        }
        else
        {
            scanf("%d%d%d", &l, &r, &x);
            update(r + 1, -x);
            update(l, x);
        }
    }
    return 0;
}