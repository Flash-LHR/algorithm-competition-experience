## 米勒罗宾素数测试

```c++
inline ll mul(ll a, ll b, ll p) { 
    if (p <= 1000000000) return a * b % p;
    else if (p <= 1000000000000LL) return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
    else {
        ll d = (ll) floor(a * (long double) b / p + 0.5);
        ll ret = (a * b - d * p) % p;
        if (ret < 0) ret += p;
        return ret;
    }
}
 
inline ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    x %= p;
    while (n) {
        if (n & 1) ans = mul(ans, x, p);
        x = mul(x, x, p);
        n >>= 1;
    }
    return ans;
}
 
bool miller_rabin(ll n, int t = 20) {
    if (n == 2) return true;
    if (n < 2 || !(n & 1)) return false;
    ll m = n - 1;
    int k = 0;
    while ((m & 1) == 0) {
        m >>= 1;
        k++;
    }
    for (int i = 0; i < t; i++) {
        ll a = rand() % (n - 1) + 1;
        ll x = qkp(a, m, n), y = 0;
        for (int j = 0; j < k; j++) {
            y = mul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if (y != 1) return false;
    }
    return true;
}
```

```c++
import java.math.BigInteger;
import java.util.*;
 
public class Main{
    public static void main(String[] args){
        BigInteger x;
        Scanner in = new Scanner(System.in);
	x = in.nextBigInteger();
	if(x.isProbablePrime(50))
		System.out.println("Yes");
	else
		System.out.println("No");
    }
}
```

## Pollard-Rho算法

```c++
int getNTFactor() {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return i;
    return -1;
}
```

```c++
int getNTFactor() {
    if (MillerRabin(n)) return n;
    int x, d = 2;
    while (d > 1) {
        x = rand() % (n - 3) + 2;
        d = gcd(n, x);
    }
    return d;
}
```

```c++
ll f(ll x, ll c) {
    return (x * x % n + c) % n
}
 
ll PollardRho(ll n) {
    if (n == 4) return 2;
    if (MillerRabin(n)) return n; 
    while (1) {
        ll c = rand() % (n - 1) + 1;
        while (t != r) {
            ll d = gcd(abs(t - r), N);
            if (d > 1) return d;
            t = f(t);
            r = f(f(r));
        }
    }
}
```

```c++
ll f(ll x, ll c) {
    return (x * x % n + c) % n
}

ll Pollard_rho(ll n) {
    if (n == 4) return 2;
    if (MillerRabin(n)) return n;
    ll s = 0, t = 0, c = rand() % (n - 1) + 1, v = 1, ed = 1;
    while (1) {
        for (int i = 1; i <= ed; i++) {
            t = f(t);
            v = v * abs(t - s) % n;
            if (i % 127 == 0) {
                ll d = gcd(v, n);
                if (d > 1) return d;
            }
        }
        ll d = gcd(v, n);
        if (d > 1) return d;
        s = t, v = 1, ed <<= 1;
    }
}
```

## 中国剩余定理及扩展

```c++
ll a[maxn], m[maxn];
 
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}
 
ll crt(int n) {
    ll M = 1, ans = 0, res, x, y;
    for (int i = 1; i <= n; i++) M *= m[i];
    for (int i = 1; i <= n; i++) {
        res = M / m[i];
        exgcd(res, m[i], x, y);
        ans = (ans + res * x * a[i] % M) % M;
    }
    if (ans < 0) ans += M;
    return ans;
}
```

```c++
ll a[maxn], m[maxn];
 
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
        if((a2 - a1) % g != 0) return -1;
        x = x * (a2 - a1) / g, m2 /= g;
        x = (x % m2 + m2) % m2;
        a1 = a1 + m1 * x, m1 = m1 * m2;
    }
    return a1;
}
```

## 卢卡斯定理及扩展

```c++
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
```

```c++
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
 
ll inv(ll a, ll p) {
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}
 
ll mul(ll x, ll n, ll p) {
    ll ans = 0;
    x %= p, n %= p;
    while (n) {
        if (n & 1) ans = (ans + x) % p;
        x = (x + x) % p;
        n >>= 1;
    }
    return ans;
}
 
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
 
ll f(ll n, ll p, ll mod) {
    if (!n) return 1;
    ll tmp = 1, res = 1;
    for (ll i = 1; i <= mod; i++)
        if (i % p) {
            tmp = tmp * i % mod;
        }
    tmp = qkp(tmp, n / mod, mod);
    for (ll i = mod * (n / mod); i <= n; i++)
        if (i % p) {
            res = res * (i % mod) % mod;
        }
    return f(n / p, p, mod) * tmp % mod * res % mod;
}
 
ll g(ll n, ll p) {
    if (n < p) return 0;
    return g(n / p, p) + n / p;
}
 
ll cal(ll n, ll m, ll p, ll mod) {
    ll fn = f(n, p, mod), fm = inv(f(m, p, mod), mod), fnm = inv(f(n - m, p, mod), mod);
    ll res = qkp(p, g(n, p) - g(m, p) - g(n - m, p), mod);
    return fn * fm % mod * fnm % mod * res % mod;
}
 
ll A[maxn], B[maxn];
 
ll exlucas(ll n, ll m, ll p) {
    ll res = p, cnt = 0;
    for (ll i = 2; i * i <= p && res > 1; i++)
        if (res % i == 0) {
            ll pk = 1;
            while (res % i == 0) pk *= i, res /= i;
            A[++cnt] = pk, B[cnt] = cal(n, m, i, pk);
        }
    if (res != 1) A[++cnt] = res, B[cnt] = cal(n, m, res, res);
    ll ans = 0;
    for (ll i = 1; i <= cnt; i++) {
        ll M = p / A[i], M1 = inv(M, A[i]);
        ans = (ans + B[i] * M % p * M1 % p) % p;
    }
    return ans;
}
```

## 二次剩余

```c++
struct T {
    ll p, d;
 
    T(ll x, ll y) {
        p = x, d = y;
    }
};
 
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
 
T mul(T a, T b, ll w, ll p) {
    T ans(0,0);
    ans.p = (a.p * b.p % p + a.d * b.d % p * w % p) % p;
    ans.d = (a.p * b.d % p + a.d * b.p % p) % p;
    return ans;
}
 
T slow_mul(T x, ll n, ll w, ll p) {
    T ans(1, 0);
    while (n) {
        if (n & 1) ans = mul(ans, x, w, p);
        x = mul(x, x, w, p);
        n >>= 1;
    }
    return ans;
}
 
ll legendre(ll a, ll p) {
    return qkp(a, (p - 1) >> 1, p);
}
 
ll get_mod(ll a, ll p) {
    a %= p;
    if (a < 0) a += p;
    return a;
}
 
ll solve(ll n, ll p) {
    if (p == 2) return 1;
    if (legendre(n, p) + 1 == p) return -1;
    ll a = -1, t, w;
    while (1) {
        a = rand() % p;
        t = a * a - n;
        w = get_mod(t, p);
        if (legendre(w, p) + 1 == p) break;
    }
    T temp(a, 1);
    T ans = slow_mul(temp, (p + 1) >> 1, w, p);
    return ans.p;
}
```

## BSGS算法及扩展

```c++
unordered_map<ll, ll> mp;
 
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
 
ll bsgs(ll a, ll b, ll p) {
    mp.clear();
    a %= p, b %= p;
    if (b == 1 || p == 1) return 0;
    int m = sqrt(p) + 1;
    ll cur = b;
    for (int i = 0; i < m; i++) {
        mp[cur] = i;
        cur = cur * a % p;
    }
    ll x = qkp(a, m, p), ans = -1, s = 1;
    for (int i = 1; i <= m; i++) {
        s = s * x % p;
        if (mp.count(s)) {
            ans = 1LL * i * m - mp[s];
            break;
        }
    }
    return ans;
}
```

```c++
unordered_map<ll, ll> mp;
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
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
 
ll inv(ll a, ll p) {
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}
 
ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}
 
ll bsgs(ll a, ll b, ll p) {
    mp.clear();
    a %= p, b %= p;
    int m = sqrt(p) + 1;
    ll cur = b;
    for (int i = 0; i < m; i++) {
        mp[cur] = i;
        cur = cur * a % p;
    }
    ll x = qkp(a, m, p), ans = -1, s = 1;
    for (int i = 1; i <= m; i++) {
        s = s * x % p;
        if (mp[s]) {
            ans = 1LL * i * m - mp[s];
            break;
        }
    }
    return ans;
}
 
ll exbsgs(ll a, ll b, ll p) {
    a %= p, b %= p;
    if (b == 1 || p == 1) return 0;
    ll d = gcd(a, p), k = 0, t = 1;
    while (d > 1) {
        if (b % d) return -1;
        b /= d, p /= d, ++k, t = t * (a / d) % p;
        if (b == t) return k;
        d = gcd(a, p);
    }
    ll ans = bsgs(a, b * inv(t, p), p);
    return ans >= 0 ? ans + k : ans;
}
```

