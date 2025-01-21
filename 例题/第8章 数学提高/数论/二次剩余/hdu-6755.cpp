#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5;
const ll Mod = 1e9 + 9;

ll factor[maxn + 10];
ll invFactor[maxn + 10];
ll invn[maxn + 10];
const ll A = 691504013;
const ll invA = 691504012;
const ll B = 308495997;
const ll D = 276601605;

ll qkp(ll a, ll b) {
    ll ans = 1, base = a;
    while (b != 0) {
        if (b & 1) ans = (ll)ans * base % Mod;
        base = (ll)base * base % Mod;
        b >>= 1;
    }
    return ans;
}

ll get_mod(ll a, ll b) {
    a += b;
    if (a >= Mod) a -= Mod;
    return a;
}

void init() {
    factor[0] = invFactor[0] = invn[0] = factor[1] = invFactor[1] = invn[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        factor[i] = factor[i - 1] * i % Mod;
        invn[i] = (ll)(Mod - Mod / i) * invn[Mod % i] % Mod;
        invFactor[i] = invFactor[i - 1] * invn[i] % Mod;
    }
}

ll getC(ll m, ll n) {
    if (n < 0 || m < 0 || m > n) return 0;
    ll ans = factor[n];
    ans = (ll)ans * invFactor[m] % Mod;
    ans = (ll)ans * invFactor[n - m] % Mod;
    return ans;
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, c, k;
        scanf("%lld%lld%lld", &n, &c, &k);
        ll ans = 0;
        ll a1 = qkp(qkp(A, k), c % (Mod - 1));
        ll q = qkp((ll)invA * B % Mod, c % (Mod - 1));
        ll n1 = n % Mod;
        ll n2 = n % (Mod - 1);
        ll a1power = qkp(a1, n2);
        ll qpower = qkp(q, n2);
        for (int i = 0; i <= k; i++) {
            ll sum = getC(i, k);
            if (i & 1) {
                sum = Mod - sum;
            }
            if (a1 == 1) {
                ans = (ans + (ll)sum * n1 % Mod) % Mod;
            } else {
                sum = (ll)sum * ((ll)a1 * (a1power - 1 + Mod) % Mod) % Mod;
                sum = (ll)sum * qkp(a1 - 1, Mod - 2) % Mod;
                ans = get_mod(ans, sum);
            }
            a1 = (ll)a1 * q % Mod;
            a1power = (ll)a1power * qpower % Mod;
        }
        printf("%lld\n", (ll)ans * qkp(D, k) % Mod);
    }
}
