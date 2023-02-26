#include <cstdio>
#include <iostream>
using namespace std;

const int N = 3e4 + 10;
int f[N], front[N], num[N];
int x, y, T;
char opt;

int find(int x)
{
    if (f[x] == x)
        return f[x];
    int fx = find(f[x]);
    front[x] += front[f[x]];
    return f[x] = fx;
}

int main()
{
    cin >> T;
    for (int i = 1; i <= 30000; ++i)
    {
        f[i] = i;
        front[i] = 0;
        num[i] = 1;
    }
    while (T--)
    {
        cin >> opt >> x >> y;
        int fx = find(x);
        int fy = find(y);

        if (opt == 'M')
        {
            front[fx] += num[fy];
            f[fx] = fy;
            num[fy] += num[fx];
            num[fx] = 0;
        }

        if (opt == 'C')
        {
            if (fx != fy)
                cout << "-1" << endl;
            else
                cout << abs(front[x] - front[y]) - 1 << endl;
        }
    }
    return 0;
}