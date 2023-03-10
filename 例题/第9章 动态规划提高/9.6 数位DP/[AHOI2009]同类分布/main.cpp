#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int num[20];
ll pw[20];
ll f[20][170][170];

ll dfs(int pos, int tar, int sum, int pro, bool lim) {
    if (pos == -1) return sum == tar && pro % sum == 0;
    if (!lim && ~f[pos][sum][pro]) return f[pos][sum][pro];
    int up = (lim ? num[pos] : 9); ll res = 0;
    for (int i = 0; i <= up; i++) {
        if (sum + i <= tar && sum + i + pos * 9 >= tar)
            res += dfs(pos - 1, tar, sum + i, (pro + i * pw[pos]) % tar, lim && i == up);
    }
    if (!lim) f[pos][sum][pro] = res;
    return res;
}

ll cal(ll n) {
    int pos = 0;
    while (n) {
        num[pos++] = n % 10;
        n /= 10;
    }
    ll res = 0;
    for (int i = 1; i <= 9 * pos; i++) {
        memset(f, -1, sizeof f);
        res += dfs(pos - 1, i, 0, 0, true);
    }
    return res;
}

void work() {
    ll a, b; scanf("%lld %lld", &a, &b);
    printf("%lld\n", cal(b) - cal(a - 1));
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < 20; i++) pw[i] = pw[i - 1] * 10;
    memset(f, -1, sizeof f);
    work();
    return 0;
}