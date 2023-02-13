#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 1000 + 10;
const int INF = 1000000000;
char g[N][N];
int dist[N][N][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int r, c;
int sx, sy;
int ans;
queue<P> q;

bool inside(int x, int y) { return x >= 0 && x < r && y >= 0 && y < c; }

void bfs(int id) // id=1时候处理每个格子首次着火的时间，id=0处理最短到达该方格的时间
{
    while (!q.empty())
    {
        P u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = u.first + dx[i], ny = u.second + dy[i];
            if (inside(nx, ny) && g[nx][ny] != '#' && dist[nx][ny][id] < 0)
            {
                dist[nx][ny][id] = dist[u.first][u.second][id] + 1;
                q.push(P(nx, ny));
            }
        }
    }
}

void check(int x, int y)
{
    if (dist[x][y][0] < 0)
        return;
    if (dist[x][y][1] < 0 || dist[x][y][0] < dist[x][y][1])
        ans = min(ans, dist[x][y][0] + 1); // 如果这个格子没有着火，或晚于到达前着火，那么更新答案
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &r, &c);
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < r; i++)
        {
            scanf("%s", g[i]);
            for (int j = 0; j < c; j++)
                if (g[i][j] == 'J')
                    sx = i, sy = j;
                else if (g[i][j] == 'F')
                {
                    dist[i][j][1] = 0;
                    q.push(P(i, j));
                }
        }
        bfs(1);
        q.push(P(sx, sy));
        dist[sx][sy][0] = 0;
        bfs(0);
        ans = INF;
        for (int i = 0; i < r; i++)
        {
            check(i, 0);
            check(i, c - 1);
        }
        for (int i = 0; i < c; i++)
        {
            check(0, i);
            check(r - 1, i);
        }
        if (ans == INF)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", ans);
    }
    return 0;
}