#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct node {
    ll x; int pre, nx;
} node[M + 5];

int a[M + 5];
int id[M + 5], invid[M + 5];
ll mi[M + 5]; int p[M + 5];

void work() {
    int n; scanf("%d", &n);
    int head = 0, tail = n + 1;
    node[head].nx = 1, node[head].x = linf;
    node[tail].pre = n, node[tail].x = linf;
    for (int i = head + 1; i < tail; i++) node[i].pre = i - 1, node[i].nx = i + 1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
    sort(id + 1, id + n + 1, [&](int x, int y) {return a[x] < a[y];});
    for (int i = 1; i <= n; i++) invid[id[i]] = i, node[i].x = a[id[i]];
    for (int i = n, u; i >= 2; i--) {
        u = invid[i];
        ll pre = node[node[u].pre].x, cur = node[u].x, nx = node[node[u].nx].x;
        mi[i] = min(abs(pre - cur), abs(nx - cur));
        if (abs(pre - cur) <= abs(nx - cur)) p[i] = id[node[u].pre];
        else p[i] = id[node[u].nx];

        node[node[u].pre].nx = node[u].nx;
        node[node[u].nx].pre = node[u].pre;
    }
    for (int i = 2; i <= n; i++) printf("%lld %d\n", mi[i], p[i]);
}

int main() {
    work();
    return 0;
}