#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

typedef long long ll;

const int M = int(1e4);
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[M + 5], b[M + 5], c[M + 5];
int id[M + 5];
int d[M * 2 + 5], len;

struct segTree {
    ll mi[(2 * M + 2) * 4 + 5];

    int lc(int k) {return k<<1;}
    int rc(int k) {return k<<1|1;}
    void push_up(int k) {mi[k] = min(mi[lc(k)], mi[rc(k)]);}

    void build(int k, int l, int r) {
        if (l == r) return mi[k] = linf, void();
        int mid = (l + r) >> 1;
        build(lc(k), l, mid);
        build(rc(k), mid + 1, r);
        push_up(k);
    }

    void update(int k, int l, int r, int a, ll b) {
        if (l == r) return cmin(mi[k], b), void();
        int mid = (l + r) >> 1;
        if (a <= mid) update(lc(k), l, mid, a, b);
        else update(rc(k), mid + 1, r, a, b);
        push_up(k);
    }

    ll query(int k, int l, int r, int a, int b) {
        if (l >= a && r <= b) return mi[k];
        int mid = (l + r) >> 1; ll res = linf;
        if (a <= mid) cmin(res, query(lc(k), l, mid, a, b));
        if (mid < b)  cmin(res, query(rc(k), mid + 1, r, a, b));
        return res;
    }
} tr;

int tofind(int x) {
    return lower_bound(d + 1, d + len + 1, x) - d;
}

void work() {
    int n, m, e; scanf("%d %d %d", &n, &m, &e);
    d[++len] = m - 1; d[++len] = e;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]), id[i] = i;
        d[++len] = a[i] - 1; d[++len] = b[i];
    }
    sort(id + 1, id + n + 1, [&](int x, int y) {return b[x] < b[y];});
    sort(d + 1, d + len + 1); len = unique(d + 1, d + len + 1) - (d + 1);
    tr.build(1, 1, len);
    tr.update(1, 1, len, tofind(m - 1), 0);
    for (int i = 1, u; i <= n; i++) {
        u = id[i];
        ll mi = tr.query(1, 1, len, tofind(a[u] - 1), len);
        tr.update(1, 1, len, tofind(b[u]), mi + c[u]);
    }
    ll mi = tr.query(1, 1, len, tofind(e), len);
    printf("%lld\n", mi == linf ? -1 : mi);
}

int main() {
    work();
    return 0;
}