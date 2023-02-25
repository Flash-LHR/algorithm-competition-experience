#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

inline ll mul(ll a, ll b, ll p) {
    if (p <= 1000000000)
        return a * b % p;
    else if (p <= 1000000000000LL)
        return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
    else {
        ll d = (ll)floor(a * (long double)b / p + 0.5);
        ll ret = (a * b - d * p) % p;
        if (ret < 0) ret += p;
        return ret;
    }
}

ll qkp(ll x, ll n, ll p) {
    if (x == 0) return n == 0;
    ll ans = 1;
    x %= p;
    while (n) {
        if (n & 1) ans = mul(ans, x, p);
        x = mul(x, x, p);
        n >>= 1;
    }
    return ans == 0 ? p : ans % p;
}

ll euler_phi(ll n) {
    int m = sqrt(n + 0.5);
    ll ans = n;
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

ll f(ll n, ll m) {
    if (n < 10) return n;
    return qkp(n % 10, f(n / 10, euler_phi(m)), m);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << f(n, m) % m << "\n";
    }
    return 0;
}
