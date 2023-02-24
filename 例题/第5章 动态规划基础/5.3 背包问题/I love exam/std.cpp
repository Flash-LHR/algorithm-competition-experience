#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch))
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

typedef long long ll;
typedef unsigned long long ull;

const int M = (int)51;
const int N = (int)11;
const int O = 501;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)998244353;

int n, m, t, p;
map<string, int> id;
int c[M][N][N];
int f[M][O];
int q[O + 5];
int g[M][O][4];

void init()
{
    id.clear();
    memset(c, 0, sizeof(c));
}

inline int calc(int i, int u, int V, int W, int k)
{
    return f[i][u + k * V] - k * W;
}

void manyBag()
{
    memset(f, -inf, sizeof(f));
    for(int i = 1; i <= n; ++i)
    {
        f[i][0] = 0;
        for(int V = 1; V <= 10; ++V)
        {
            for(int W = 1; W <= 10; ++W)
            {
                int C = c[i][V][W];
                for(int u = 0; u < V; ++u)
                {
                    int l = 1, r = 0;
                    int maxp = (t - u) / V;
                    for(int k = maxp - 1; k >= max(maxp - C, 0); --k)
                    {
                        while(l <= r && calc(i, u, V, W, q[r]) <= calc(i, u, V, W, k)) --r;
                        q[++r] = k;
                    }
                    for(int p = maxp; p >= 0; --p)
                    {
                        while(l <= r && q[l] > p - 1) ++l;
                        if(l <= r) f[i][u + p * V] = max(f[i][u + p * V],
                                                         calc(i, u, V, W, q[l]) + p * W);
                        if(p - C - 1 >= 0)
                        {
                            while(l <= r &&
                                  calc(i, u, V, W, q[r]) <= calc(i, u, V, W, p - C - 1)) --r;
                            q[++r] = p - C - 1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= t; ++j) f[i][j] = min(f[i][j], 100);
    }
}

void groupBag()
{
    memset(g, -inf, sizeof(g));
    g[0][0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= t; ++j)
        {
            for(int l = 0; l <= p; ++l)
            {
                for(int k = 0; k <= j; ++k)
                {
                    if(l > 0 && f[i][k] < 60)
                    {
                        g[i][j][l] = max(g[i][j][l], g[i - 1][j - k][l - 1] + f[i][k]);
                    }
                    if(f[i][k] >= 60)
                    {
                        g[i][j][l] = max(g[i][j][l], g[i - 1][j - k][l] + f[i][k]);
                    }
                }
            }
        }
    }
}

void work()
{
    init();
    cin >> n;
    string name;
    for(int i = 1; i <= n; ++i)
    {
        cin >> name;
        id[name] = i;
    }
    cin >> m;
    for(int i = 1, x, y; i <= m; ++i)
    {
        cin >> name >> x >> y;
        ++c[id[name]][y][x];
    }
    cin >> t >> p;
    manyBag();
    groupBag();
    int mx = -1;
    for(int j = 0; j <= t; ++j)
    {
        for(int k = 0; k <= p; ++k) mx = max(mx, g[n][j][k]);
    }
    cout << mx << "\n";
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int ca = 1; ca <= T; ++ca)
    {
//        printf("Case #%d:\n", ca);
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}
