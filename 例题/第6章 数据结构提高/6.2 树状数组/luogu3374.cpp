#include <cstdio>
using namespace std;

const int N = 5e5 + 10;
int c[N];
int n, m;

int lowbit(int x)
{
    return x & -x;
}

int getsum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans;
}

void add(int x, int k)
{
    while (x <= n)
    {
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int opt, x, y;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        add(i, x);
    }
    while (m--)
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
            add(x, y);
        else
            printf("%d\n", getsum(y) - getsum(x - 1));
    }
    return 0;
}