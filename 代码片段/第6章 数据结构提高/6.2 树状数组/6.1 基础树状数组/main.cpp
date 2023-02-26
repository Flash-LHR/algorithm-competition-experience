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
