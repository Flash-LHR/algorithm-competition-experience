#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int Mod = 1e6 + 3;

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

ll inv(ll x, ll p) {
    return qkp(x, p - 2, p);
}

ll cal(ll n, ll m, ll p) {
    if (m > n) return 0;
    ll u = 1, d = 1;
    for (int i = n - m + 1; i <= n; i++) u = u * i % p;
    for (int i = 1; i <= m; i++) d = d * i % p;
    return u * inv(d, p) % p;
}

ll lucas(ll n, ll m, ll p) {
    if (!m) return 1;
    return cal(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    ll n, l, r;
    cin >> T;
    while(T--) {
        cin >> n >> l >> r;
        ll m = r - l + 1;
        cout << (lucas(n + m, n, Mod) - 1 + Mod) % Mod << endl;
    }
    return 0;
}