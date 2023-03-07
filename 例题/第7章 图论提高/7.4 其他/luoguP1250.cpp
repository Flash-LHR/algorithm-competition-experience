#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f;
const int M = 3e4 + 10;
const int N = 1e5 + 10;
struct node
{
    int next, to, dis;
} e[N];
int cnt, dis[M], vis[M], head[M], n, h;

void add(int u, int v, int w)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].dis = w;
    head[u] = cnt;
}

void spfa(int s)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
        vis[i] = 0;
    }
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].dis)
            {
                dis[v] = dis[u] + e[i].dis;
                if (vis[v] == 0)
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return;
}

int main()
{
    int x, y, z, s;
    scanf("%d%d", &n, &h);
    s = n + 1;
    for (int i = 0; i <= n; ++i)
    {
        add(s, i, 0);
    }
    for (int i = 1; i <= h; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(y, x - 1, -z);
    }
    for (int i = 1; i <= n; ++i)
    {
        add(i - 1, i, 1);
        add(i, i - 1, 0);
    }
    spfa(s);
    int minn = INF;
    for (int i = 0; i <= n; ++i)
    {
        minn = min(minn, dis[i]);
    }
    printf("%d\n", dis[n] - minn);
    return 0;
}