#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int num[40];
ll f[40][2][3];

ll dfs(int pos, bool have, int cnt, bool lim) {
    if (pos == -1) return have;
    if (!lim && ~f[pos][have][cnt]) return f[pos][have][cnt];
    int up = (lim ? num[pos] : 9); ll res = 0;
    for (int i = 0; i <= up; i++) {
        if (have) res += dfs(pos - 1, have, cnt, lim && i == up);
        else if (i != 6) res += dfs(pos - 1, have, 0, lim && i == up);
        else if (cnt == 2) res += dfs(pos - 1, true, 0, lim && i == up);
        else res += dfs(pos - 1, have, cnt + 1, lim && i == up);
    }
    if (!lim) f[pos][have][cnt] = res;
    return res;
}

ll cal(ll n) {
    int pos = 0;
    while (n) {
        num[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1, false, 0, true);
}

void work() {
    int n; scanf("%d", &n);
    ll l = 1, r = ll(1e35), mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (cal(mid) >= n) r = mid;
        else l = mid + 1;
    }
    printf("%lld\n", r);
}

int main() {
    memset(f, -1, sizeof f);
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}