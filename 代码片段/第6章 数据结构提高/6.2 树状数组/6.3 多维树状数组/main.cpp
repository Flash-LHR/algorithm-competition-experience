// 单点修改+区间查询

void updata(int x, int y, int d)
{
    int temp = y;
    while (x <= n)
    {
        y = temp;
        while (y <= n)
        {
            arr[x][y] += d;
            y += lowbit(y);
        }
        x += lowbit(x);
    }
}

int getsum(int x, int y)
{
    int res = 0, temp = y;
    while (x > 0)
    {
        y = temp;
        while (y > 0)
        {
            res += arr[x][y];
            y -= lowbit(y);
        }
        x -= lowbit(x);
    }
    return res;
}

// 区间修改+单点查询

void updata(int x, int y, int d)
{
    int j = y;
    while (x <= n)
    {
        int y = j;
        while (y <= m)
        {
            tree[x][y] += d;
            y += lowbit(y);
        }
        x += lowbit(x);
    }
}

ll getsum(int x, int y)
{
    ll res = 0;
    int j = y;
    while (x > 0)
    {
        y = j;
        while (y > 0)
        {
            res += tree[x][y];
            y -= lowbit(y);
        }
        x -= lowbit(x);
    }
    return res;
}

void range_add(int a, int b, int c, int d, int k)
{
    updata(a, b, k);
    updata(a, d + 1, -k);
    updata(c + 1, b, -k);
    updata(c + 1, d + 1, k);
}
