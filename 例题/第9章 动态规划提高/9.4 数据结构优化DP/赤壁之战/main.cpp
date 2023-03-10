#include <bits/stdc++.h>
using namespace std;

const int M = int(1e3);
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;

int a[M + 5], d[M + 5], len;
int f[2][M + 5];

struct TA {
    int a[M + 5], n;
    void init(int _n) {n = _n; memset(a, 0, sizeof(a[0]) * (n + 1));}
    int lowbit(int n) {return n & -n;}
    void add(int p, int x) {while (p <= n) (a[p] += x) %= mod, p += lowbit(p);}
    int ask(int p) {int s = 0; while (p) (s += a[p]) %= mod, p -= lowbit(p); return s;}
    int ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr[2];

int tofind(int x) {
    return lower_bound(d + 1, d + len + 1, x) - d;
}

void work() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), d[i] = a[i];
    a[0] = d[len = n + 1] = -inf;
    sort(d + 1, d + len + 1); len = unique(d + 1, d + len + 1) - (d + 1);
    for (int i = 0; i <= n; i++) a[i] = tofind(a[i]);
    tr[0].init(len); memset(f[0], 0, sizeof f[0]); f[0][0] = 1;
    for (int i = 1, u; i <= m; i++) {
        u = i & 1;
        tr[u].init(len);
        for (int j = i; j <= n; j++) {
            tr[u ^ 1].add(a[j - 1], f[u ^ 1][j - 1]);
            f[u][j] = tr[u ^ 1].ask(a[j] - 1);
        }
    }
    printf("%lld\n", accumulate(f[m & 1] + m, f[m & 1] + n + 1, 0ll) % mod);
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}