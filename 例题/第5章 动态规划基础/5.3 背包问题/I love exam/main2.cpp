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
int c[N + 5][11][11];
int f[N + 5][105];
int q[105];
int g[2][O + 5][4];

void multiple() {
    auto solve = [&](int *f, int V, int v, int w, int s) {
        for (int j = 0; j < v; j++) {
            int l = 1, r = 0, mx = (V - j) / v;
            for (int k = mx - 1; k >= max(0, mx - s); k--) {
                while (l <= r && f[j + q[r] * v] - q[r] * w 
                    <= f[j + k * v] - k * w) r--;
                q[++r] = k;
            }
            for (int k = mx; k >= 1; k--) {
                if (l <= r && q[l] == k) l++;
                cmax(f[j + k * v], f[j + q[l] * v] + (k - q[l]) * w);
                if (k - s - 1 >= 0) {
                    while (l <= r && f[j + q[r] * v] - q[r] * w 
                        <= f[j + (k - s - 1) * v] - (k - s - 1) * w) r--;
                    q[++r] = k - s - 1;
                }
            }
        }
    };

    memset(f, -inf, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][0] = 0;
        for (int x = 1; x <= 10; x++) {
            for (int y = 1; y <= 10; y++) if (c[i][x][y]) {
                solve(f[i], 100, y, x, c[i][x][y]);
            }
        }
        for (int j = 0; j <= 100; j++) cmin(f[i][j], 100);
    }
}

void group() {
    memset(g, -inf, sizeof g);
    g[0][0][0] = 0;
    for (int i = 1, u; i <= n; i++) {
        u = i & 1;
        memset(g[u], -inf, sizeof(g[u]));
        for (int j = t; j >= 0; j--) {
            for (int k = 0; k <= p; k++) {
                for (int l = 0; l <= j; l++) {
                    if (k > 0 && f[i][l] < 60)
                        cmax(g[u][j][k], g[u ^ 1][j - l][k - 1] + f[i][l]);
                    if (f[i][l] >= 60)  
                        cmax(g[u][j][k], g[u ^ 1][j - l][k] + f[i][l]);
                }
            }
        }
    }
}

void work() {
    id.clear();
    memset(c, 0, sizeof c);
    cin >> n;
    string name;
    for (int i = 1; i <= n; i++) {
        cin >> name;
        id[name] = i;
    }
    cin >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> name >> x >> y;
        c[id[name]][x][y]++;
    }
    cin >> t >> p;
    multiple();
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