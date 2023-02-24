#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll, ll> f;

ll dfs(ll u) {
    if (f.count(u)) return f[u];
    if (u == 0 || u == 1) return f[u] = 0;
    if (u & 1) return f[u] = dfs(u / 2) + dfs(u / 2 + 1) + 1;
    return f[u] = dfs(u / 2) * 2;
}

void work() {
    ll n; scanf("%lld", &n);
    printf("%lld\n", dfs(n));
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}