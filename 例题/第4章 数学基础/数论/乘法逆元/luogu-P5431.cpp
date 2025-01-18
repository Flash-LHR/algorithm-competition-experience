#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e6 + 10;

ll a[maxn], s[maxn], sv[maxn];

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * x % p;
        }
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n;
    ll p, k;
    n = read();
    p = read();
    k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    s[0] = 1;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] * a[i] % p;
    sv[n] = qkp(s[n], p - 2, p);
    for (int i = n; i >= 1; i--) sv[i - 1] = sv[i] * a[i] % p;
    ll ans = 0, t = 1;
    for (int i = 1; i <= n; i++) {
        t = t * k % p;
        ans = (ans + s[i - 1] * sv[i] % p * t % p) % p;
    }
    cout << ans << endl;
    return 0;
}
