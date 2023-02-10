#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, h[M + 5];
int st[M + 5], tp;
int l[M + 5], r[M + 5];

void work() {
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    h[st[tp = 1] = 0] = -1;
    for (int i = 1; i <= n; i++) {
        while (tp && h[st[tp]] >= h[i]) tp--;
        l[i] = st[tp] + 1;
        st[++tp] = i;
    }
    h[st[tp = 1] = n + 1] = -1;
    for (int i = n; i >= 1; i--) {
        while (tp && h[st[tp]] >= h[i]) tp--;
        r[i] = st[tp] - 1;
        st[++tp] = i;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, (ll)(r[i] - l[i] + 1) * h[i]);
    printf("%lld\n", ans);
}

int main() {
    while (~scanf("%d", &n) && n) work();
    return 0;
}