#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int c[N], n, a[N], b[N];

int lowbit(int x)
{
    return x & -x;
}

int ask(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

void update(int x, int d)
{
    while (x <= n)
    {
        c[x] += d;
        x += lowbit(x);
    }
}

int main()
{
    scanf("%d", &n);
    a[1] = 0;
    for (int i = 2; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        update(i, 1);
    for (int i = n; i >= 1; --i)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (ask(mid) > a[i])
                r = mid - 1;
            else
                l = mid;
        }
        b[i] = l + 1;
        update(l + 1, -1);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", b[i]);
    return 0;
}