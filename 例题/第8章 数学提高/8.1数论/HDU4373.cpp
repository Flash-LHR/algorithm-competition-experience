#include <iostream>

using namespace std;
typedef long long ll;
const int Mod1 = 97;
const int Mod2 = 3761599;
const int Mod = Mod1 * Mod2;
const int maxn = 1e5 + 10;

int a[20];
ll fac1[Mod1 + 10], fac2[Mod2 + 10];
ll inv1, inv2;

ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    x %= p;
    while (n) {
        if (n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}

ll cal(ll n, ll m, ll p, ll *fac) {
    if (n < m) return 0;
    return fac[n] * qkp(fac[m] * fac[n - m], p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p, ll *fac) {
    if (!m) return 1;
    return cal(n % p, m % p, p, fac) * lucas(n / p, m / p, p, fac);
}

void init() {
    fac1[0] = fac2[0] = 1;
    for (int i = 1; i < Mod1; i++)
        fac1[i] = fac1[i - 1] * i % Mod1;
    for (int i = 1; i < Mod2; i++)
        fac2[i] = fac2[i - 1] * i % Mod2;
    inv1 = Mod2 * qkp(Mod2, Mod1 - 2, Mod1);
    inv2 = Mod1 * qkp(Mod1, Mod2 - 2, Mod2);
}

int main() {
    int t, n, m, k, kase = 0;
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0, x; i < k; i++)
            scanf("%d", &a[i]);
        a[k] = m;
        ll ans = 1, m1, m2, m3;
        for (int i = 1; i <= k; i++) {
            int q = a[i] - a[i - 1];
            m1 = lucas(n + q - 1, q, Mod1, fac1);
            m2 = lucas(n + q - 1, q, Mod2, fac2);
            m3 = (m1 * inv1 + m2 * inv2) % Mod;
            ans = ans * m3 % Mod;
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
