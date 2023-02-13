#include <time.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int random(int n)
{
    return (long long)rand() * rand() % n;
}

const int maxn = 1e6 + 10;
int n, m, cnt, f[maxn];

// 随机生成一棵带权树
void randTree(int val_range)
{
    for (int i = 2; i <= n; i++)
    {
        // 从2~n之间的每个点向1~i-1之间的点随机连一条边
        int fa = random(i - 1) + 1;
        int val = random(val_range) + 1;
        printf("%d %d %d", fa, i, val);
    }
}

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void randTree()
{
    srand(time(0));
    int n = 30000; // 生成树的点数
    cout << n << endl;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    while (cnt < n - 1)
    {
        int x = rand() * rand(), y = rand() * rand();
        x = x % n + 1;
        y = y % n + 1;
        int x1 = find(x), y1 = find(y);
        if (x1 != y1)
            f[x1] = y1, cnt++, cout << x << " " << y << endl;
    }
}

pair<int, int> e[1000005];   // 保存数据
map<pair<int, int>, bool> h; // 防止重边

void randGraph(int n, int m)
{
    // 先生成一棵树，保证连通
    for (int i = 1; i < n; i++)
    {
        int fa = random(i) + 1;
        e[i] = make_pair(fa, i + 1);
        h[e[i]] = h[make_pair(i + 1, fa)] = 1;
    }
    // 再生成剩余的m-n+1条边
    for (int i = n; i <= m; i++)
    {
        int x, y;
        do
        {
            x = random(n) + 1;
            y = random(n) + 1;
        } while (x == y || h[make_pair(x, y)]);
        e[i] = make_pair(x, y);
        h[e[i]] = h[make_pair(y, x)] = 1;
    }
    // 随机打乱并输出
    random_shuffle(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", e[i].first, e[i].second);
}

#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
    for (int T = 1; T <= 10000; T++)
    {
        //
        system("C:\\random.exe");
        // 当前程序已经运行的CPU时间，Windows下单位ms，Unix下单位s
        double st = clock();
        system("C:\\sol.exe");
        double ed = clock();
        system("C:\\bf.exe");
        if (system("fc C:\\data.out C:\\data.ans"))
        {
            puts("Wrong Answer!");
            // 程序立刻退出，此时data.in即为发生错误的数据
            return 0;
        }
        else
        {
            printf("Accepted, 测试点 #%d, 用时 %.0lfms\n", T, ed - st);
        }
    }
    return 0;
}