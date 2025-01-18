#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

ll a[maxn];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    ll k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        ll g = 0;
        for (int i = 2; i <= n; i++) {
            g = gcd(g, a[i] - a[i - 1]);
        }
        if ((k - a[1]) % g == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
