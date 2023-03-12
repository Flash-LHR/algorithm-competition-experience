#include <iostream>

using namespace std;
const int Mod = 1e9 + 7;
const int maxn = 2e5 + 10;

typedef __int128 ll;

ll a[maxn], m[maxn];

inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void write(__int128 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

ll mul(ll x, ll n, ll p) {
    ll ans = 0;
    while (n) {
        if (n & 1) ans = (ans + x) % p;
        x = (x + x) % p;
        n >>= 1;
    }
    return ans;
}

ll excrt(int n) {
    ll a1 = a[1], m1 = m[1], a2, m2, x, y;
    for (int i = 2; i <= n; i++) {
        a2 = a[i], m2 = m[i];
        ll g = exgcd(m1, m2, x, y);
        x = x * (a2 - a1) / g, m2 /= g;
        x = (x % m2 + m2) % m2;
        a1 = a1 + m1 * x, m1 = m1 * m2;
    }
    return a1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        m[i] = read();
        a[i] = read();
    }
    write(excrt(n));
    return 0;
}