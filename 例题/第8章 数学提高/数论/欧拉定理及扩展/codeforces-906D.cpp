#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

ll a[maxn];
map<ll, ll> mp;

ll Mod(ll x, ll p) {
    return x >= p ? x % p + p : x;
}

ll getphi(ll p) {
    if (mp.count(p)) return mp[p];
    ll n = p, ans = p;
    int m = sqrt(p + 0.5);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return mp[p] = ans;
}

ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = Mod(ans * x, p);
        x = Mod(x * x, p);
        n >>= 1;
    }
    return ans;
}

ll cal(int l, int r, ll p) {
    if (l == r || p == 1) return Mod(a[l], p);
    return qkp(a[l], cal(l + 1, r, getphi(p)), p);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, p, q, l, r;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << cal(l, r, p) % p << "\n";
	}
	return 0;
}
