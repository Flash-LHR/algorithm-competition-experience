#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

const int M = 15000;
const int N = 50;
const int O = 500;
const int inf = 0x3f3f3f3f;

int n, m, t, p;
map<string, int> id;
int c[M + 5], x[M + 5], y[M + 5];
int f[N + 5][105];
int g[2][O + 5][4];

void zeroOne() {
    memset(f, inf, sizeof f);
    for (int i = 1; i <= n; i++) f[i][0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 100; j >= 0; j--)
            cmin(f[c[i]][min(100, j + x[i])], f[c[i]][j] + y[i]);
}

void group() {
    memset(g, -inf, sizeof g);
    g[0][0][0] = 0;
    for (int i = 1, u; i <= n; i++) {
        u = i & 1;
        memset(g[u], -inf, sizeof(g[u]));
        for (int j = t; j >= 0; j--) {
            for (int k = 0; k <= p; k++) {
                for (int l = 0; l <= 100; l++) if (j >= f[i][l]) {
                    if (l < 60 && k > 0)
                        cmax(g[u][j][k], g[u ^ 1][j - f[i][l]][k - 1] + l);
                    if (l >= 60) cmax(g[u][j][k], g[u ^ 1][j - f[i][l]][k] + l);
                }
            }
        }
    }
}

void work() {
    id.clear();
    cin >> n;
    string name;
    for (int i = 1; i <= n; i++) {
        cin >> name;
        id[name] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> name >> x[i] >> y[i];
        c[i] = id[name];
    }
    cin >> t >> p;
    zeroOne();
    group();
    int mx = -1;
    for (int i = 0; i <= t; i++)
        for (int j = 0; j <= p; j++) mx = max(mx, g[n & 1][i][j]);
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}