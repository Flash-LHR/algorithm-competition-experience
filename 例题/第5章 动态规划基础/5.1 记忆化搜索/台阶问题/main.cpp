#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int mod = (int)100003;

int n, k;
int f[M + 5];

int dfs(int u) {
    if (~f[u]) return f[u];
    if (u == n) return f[u] = 1;
    f[u] = 0;
    for (int i = 1; i <= k && u + i <= n; i++) (f[u] += dfs(u + i)) %= mod;
    return f[u];
}

void work() {
    scanf("%d %d", &n, &k);
    memset(f, -1, sizeof(int) * (n + 1));
    printf("%d\n", dfs(0));
}

int main() {
    work();
    return 0;
}