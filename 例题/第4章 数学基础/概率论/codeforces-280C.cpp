#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> g[maxn];
int d[maxn];

void dfs(int fa, int u) {
    d[u] = d[fa] + 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(u, v);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 1);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1.0 / d[i];
    }
    printf("%.6lf\n", ans);
    return 0;
}