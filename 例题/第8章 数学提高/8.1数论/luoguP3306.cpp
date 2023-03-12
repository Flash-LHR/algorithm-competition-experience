#include <iostream>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

map<LL, LL> hash;
LL p, a, b, x1, xn;

LL ksm(LL a, LL k) {
    LL ans = 1;
    a %= p;
    for (; k; k >>= 1, a = a * a % p)
        if (k & 1) ans = ans * a % p;
    return ans;
}

LL bsgs(LL a, LL b, LL p) {
    if (a % p == 0) return -1;
    hash.clear();
    LL m = ceil(sqrt(p));
    LL am = ksm(a, m);
    for (int j = 0; j <= m; j++) {
        hash[b] = j;
        b = b * a % p;
    }
    LL mul = 1;
    for (int i = 1; i <= m; i++) {
        mul = mul * am % p;
        if (hash[mul]) return i * m - hash[mul] + 1;
    }
    return -1;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld", &p, &a, &b, &x1, &xn);
        if (x1 == xn) {
            printf("1\n");
            continue;
        }
        if (a == 0) {
            if (xn == b) printf("2\n"); else printf("-1\n");
            continue;
        }
        if (a == 1 && b == 0) {
            printf("-1\n");
            continue;
        }

        if (a == 1) {
            LL nyb = ksm(b, p - 2);
            LL ans = ((((xn - x1) % p + p) % p) * nyb % p) % p;
            printf("%lld\n", ans + 1);
            continue;
        }

        LL inv = b % p * ksm(a - 1, p - 2) % p;
        LL shou = (xn % p + inv) % p;
        LL hou = (x1 % p + inv) % p;
        hou = ksm(hou, p - 2) % p;
        LL ans = bsgs(a, shou * hou % p, p);
        printf("%lld\n", ans);
    }
}