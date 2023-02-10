#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, h[M + 5], w[M + 5];
int st[M + 5], tp;

void work() {
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    ll ans = 0;
    h[n + 1] = tp = 0;
    for (int i = 1; i <= n + 1; i++) {
        int width = 0;
        while (tp && st[tp] >= h[i]) {
            width += w[tp];
            ans = max(ans, (ll)width * st[tp]);
            tp--;
        }
        st[++tp] = h[i];
        w[tp] = width + 1;
    }
    printf("%lld\n", ans);
}

int main() {
    while (~scanf("%d", &n) && n) work();
    return 0;
}