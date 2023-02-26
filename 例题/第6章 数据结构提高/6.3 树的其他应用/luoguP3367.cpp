#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
int f[10010];

int find(int k)
{
    if (f[k] == k)
        return k;
    return f[k] = find(f[k]);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> z >> x >> y;
        if (z == 1)
            f[find(x)] = find(y);
        else if (find(x) == find(y))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}