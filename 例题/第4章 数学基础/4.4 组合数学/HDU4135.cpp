#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

vector<ll> prime;

void init(ll n) {
    prime.clear();
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prime.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) prime.push_back(n);
}

ll solve(ll r) {
    ll ans = 0;
    for (ll s = 1; s < (1 << prime.size()); s++) {
        ll num = 1, cnt = 0;
        for (int i = 0; i < prime.size(); i++) {
            if (s & (1 << i)) {
                cnt++;
                num *= prime[i];
            }
        }
        ll res = r / num;
        if (cnt & 1)
            ans += res;
        else
            ans -= res;
    }
    return r - ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, kase = 0;
    ll l, r, n;
    cin >> t;
    while (t--) {
        cin >> l >> r >> n;
        init(n);
        cout << "Case #" << ++kase << ": " << solve(r) - solve(l - 1) << "\n";
    }
    return 0;
}
