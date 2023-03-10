#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = int(1e5);

ll s[M + 5];
ll f[M + 5];
int q[M + 5];

void work() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]), s[i] += s[i - 1];
    int l = 1, r = 0;
    for (int i = 0; i <= k; i++) {
        f[i] = s[i];
        while (l <= r && f[q[r]] - s[q[r] + 1] <= f[i] - s[i + 1]) --r;
        q[++r] = i;
    }
    for (int i = k + 1; i <= n; i++) {
        while (l <= r && i - (q[l] + 2) + 1 > k) ++l;
        f[i] = f[q[l]] - s[q[l] + 1] + s[i];
        while (l <= r && f[q[r]] - s[q[r] + 1] <= f[i] - s[i + 1]) --r;
        q[++r] = i;
    }
    printf("%lld\n", *max_element(f + 1, f + n + 1));
}

int main() {
    work();
    return 0;
}