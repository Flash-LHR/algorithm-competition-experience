#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = int(2e3);
const int N = int(2e5);
const int mod = int(1e9) + 7;

int x[M + 5], y[M + 5], id[M + 5];
int inv[N + 5], fac[N + 5], invfac[N + 5];
int f[M + 5];

void init() {
    fac[0] = fac[1] = invfac[0] = invfac[1] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
        fac[i] = (ll)fac[i - 1] * i % mod;
        invfac[i] = (ll)invfac[i - 1] * inv[i] % mod;
        assert((ll)fac[i] * invfac[i] % mod == 1);
    }
}

int C(int n, int m) {
    return (ll)fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void work() {
    int n, m, c; scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= c; i++) scanf("%d %d", &x[i], &y[i]), id[i] = i;
    x[0] = 1, y[0] = 1;
    ++c; x[c] = n, y[c] = m, id[c] = c;
    sort(id + 1, id + c + 1, [&](int a, int b) {
        if (x[a] != x[b]) return x[a] < x[b];
        return y[a] < y[b];
    });
    f[0] = 1;
    for (int i = 1, u; i <= c; i++) {
        u = id[i];
        f[i] = C(x[u] + y[u] - 2, x[u] - 1);
        for (int j = 1, v; j < i; j++) {
            v = id[j];
            if (x[u] >= x[v] && y[u] >= y[v])
                f[i] -= (ll)f[j] * C(x[u] - x[v] + y[u] - y[v], x[u] - x[v]) % mod;
            if (f[i] < 0) f[i] += mod;
        }
    }
    printf("%d\n", f[c]);
}

int main() {
    init();
    work();
    return 0;
}