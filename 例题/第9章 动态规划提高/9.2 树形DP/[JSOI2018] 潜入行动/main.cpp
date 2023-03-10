#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = int(1e5);
const int N = int(1e2);
const int mod = int(1e9) + 7;

int n, k;
int sz[M + 5];
vector<int> g[M + 5];
int backup[N + 5][2][2];
int f[M + 5][N + 5][2][2];

void dfs(int u, int fa) {
    sz[u] = 1, f[u][0][0][0] = 1, f[u][1][1][0] = 1;
    for (const int &v: g[u]) if (v != fa) {
        dfs(v, u);
        memcpy(backup, f[u], sizeof f[u]);
        memset(f[u], 0, sizeof f[u]);
        for (int i = 0; i <= min(k, sz[u]); i++) {
            for (int j = 0; j <= min(k - i, sz[v]); j++) {
                (f[u][i + j][0][0] += (ll)backup[i][0][0] * f[v][j][0][1] % mod) %= mod;
                (f[u][i + j][0][1] += ((ll)backup[i][0][1] * (f[v][j][0][1] + f[v][j][1][1]) 
                                        + (ll)backup[i][0][0] * f[v][j][1][1]) % mod) %= mod;
                (f[u][i + j][1][0] += (ll)backup[i][1][0] * (f[v][j][0][0] + f[v][j][0][1]) % mod) %= mod;
                (f[u][i + j][1][1] += (backup[i][1][1] 
                                        * ((ll)f[v][j][0][0] + f[v][j][0][1] + f[v][j][1][0] + f[v][j][1][1])
                                        + (ll)backup[i][1][0] * (f[v][j][1][0] + f[v][j][1][1])) % mod) %= mod;
            }
        }
        sz[u] += sz[v];
    }
}

void work() {
    scanf("%d %d", &n, &k);
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", (f[1][k][0][1] + f[1][k][1][1]) % mod);
}

int main() {
    work();
    return 0;
}