#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e5;
const int inf = 0x3f3f3f3f;

int n, m;
ll s[M + 5];
int q[M + 5];

void work() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]), s[i] += s[i - 1];
    int l = 1, r = 0;
    q[++r] = 0;
    ll ans = -inf;
    for (int i = 1; i <= n; i++) {
        while (l <= r && i - q[l] > m) l++;
        ans = max(ans, s[i] - s[q[l]]);
        while (l <= r && s[i] <= s[q[r]]) r--;
        q[++r] = i;
    }
    printf("%lld\n", ans);
}

int main() {
    work();
    return 0;
}