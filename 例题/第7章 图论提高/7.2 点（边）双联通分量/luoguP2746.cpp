#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int n, head[N], cnt = 0, col = 0, sum;
int top = 1, sta[N], color[N], tim[N], low[N], ins[N];
int in[N], out[N];
struct net
{
    int to, next;
} e[1000000];

void add(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}

void tarjian(int x)
{
    sum++;
    tim[x] = low[x] = sum;
    sta[top] = x;
    top++;
    ins[x] = 1;
    for (int w = head[x]; w != 0; w = e[w].next)
    {
        if (ins[e[w].to] == 0)
        {
            tarjian(e[w].to);
            low[x] = min(low[x], low[e[w].to]);
        }
        else if (ins[e[w].to] == 1)
            low[x] = min(low[x], tim[e[w].to]);
    }

    if (tim[x] == low[x])
    {
        col++;
        do
        {
            top--;
            color[sta[top]] = col;
            ins[sta[top]] = -1;
        } while (sta[top] != x);
    }
    return;
}

int hym[1000000][3];
int main()
{
    int k = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (x != 0)
        {
            k++;
            add(i, x);
            hym[k][1] = i;
            hym[k][2] = x;
            scanf("%d", &x);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!ins[i])
            tarjian(i);
    for (int i = 1; i <= k; i++)
        if (color[hym[i][1]] != color[hym[i][2]])
        {
            out[color[hym[i][1]]]++;
            in[color[hym[i][2]]]++;
        }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= col; i++)
    {
        if (in[i] == 0)
            ans1++;
        if (out[i] == 0)
            ans2++;
    }
    if (col == 1)
        cout << 1 << endl
             << 0;
    else
        cout << ans1 << endl
             << max(ans1, ans2);
    return 0;
}