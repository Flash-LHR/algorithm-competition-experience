/*
// 米勒罗宾算法
inline ll mul(ll a, ll b, ll p) {   //wa了尝试慢速乘
    if (p <= 1000000000) return a * b % p;  //1e9
    else if (p <= 1000000000000LL) return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;  //1e12
    else {
        ll d = (ll) floor(a * (long double) b / p + 0.5);
        ll ret = (a * b - d * p) % p;
        if (ret < 0) ret += p;
        return ret;
    }
}

//inline ll mul(ll x, ll n, ll p) {
//    ll ans = 0;
//    x %= p;
//    while (n) {
//        if (n & 1) ans = (ans + x) % p;
//        x = (x + x) % p;
//        n >>= 1;
//    }
//    return ans;
//}

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
*/

/*
// Pollard-Rho
int getNTFactor() {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return i;
    return -1;
}

int getNTFactor() {
    if (MillerRabin(n)) return n;
    int x, d = 2;
    while (d > 1) {
        x = rand() % (n - 3) + 2;  // 生成2和n-1之间的随机数
        d = gcd(n, x);       // 求gcd
    }
    return d;
}
//龟兔赛跑PR算法
ll f(ll x, ll c) {
    return (x * x % n + c) % n
}

ll PollardRho(ll n) {
    if (n == 4) return 2;  //特判4
    if (MillerRabin(n)) return n;  //特判质数
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
//倍增PR算法
ll f(ll x, ll c) {
    return (x * x % n + c) % n
}

ll Pollard_rho(ll n) {
    if (n == 4) return 2;  //特判4
    if (MillerRabin(n)) return n;  //特判质数
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
*/

/*
//中国剩余定理
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
// 扩展中国剩余定理
//typedef __int128 ll;   wa了就是中间乘法溢出了尝试__int128

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
*/

/*
//lucas定理
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

ll inv(ll x, ll p) {  //求逆元
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
// exlucas
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
*/

/*
//线性筛选求莫比乌斯函数
bool isprime[maxn];
int mu[maxn], prime[maxn];

void initMu() {
    mu[1] = 1;
    int cnt = 0;
    for (int i = 2; i < maxn; i++) {
        if (!isprime[i]) prime[cnt++] = i, mu[i] = -1;
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j]) mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}
*/

/*
// BSGS算法
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
 */

/*
// exbsgs算法
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
 */

/*
//Pohlig-Hellman算法
namespace PhoRho { //Phollard-Rho
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ll fastpow(ll x, ll p, ll mod) {
        ll ans = 1;
        while (p) {
            if (p & 1) ans = (__int128) ans * x % mod;
            x = (__int128) x * x % mod;
            p >>= 1;
        }
        return ans;
    }

    ll max_factor;

    bool MillerRabin(ll x, ll b) {
        ll k = x - 1;
        while (k) {
            ll cur = fastpow(b, k, x);
            if (cur != 1 && cur != x - 1) return false;
            if ((k & 1) == 1 || cur == x - 1) return true;
            k >>= 1;
        }
        return true;
    }

    bool prime(ll x) {
        if (x == 46856248255981ll || x < 2) return false;
        if (x == 2 || x == 3 || x == 7 || x == 61 || x == 24251) return true;
        return MillerRabin(x, 2) && MillerRabin(x, 3) && MillerRabin(x, 7) && MillerRabin(x, 61);
    }

    ll f(ll x, ll c, ll n) {
        return ((__int128) x * x + c) % n;
    }

    ll PRho(ll x) {
        ll s = 0, t = 0, c = 1ll * rand() * (x - 1) + 1;
        int stp = 0, goal = 1;
        ll val = 1;
        for (goal = 1;; goal <<= 1, s = t, val = 1) {
            for (stp = 1; stp <= goal; ++stp) {
                t = f(t, c, x);
                val = (__int128) val * abs(t - s) % x;
                if (stp % 127 == 0) {
                    ll d = gcd(val, x);
                    if (d > 1) return d;
                }
            }
            ll d = gcd(val, x);
            if (d > 1) return d;
        }
    }

    void fac(ll x) {
        if (x <= max_factor || x < 2) {
            return;
        }
        if (prime(x)) {
            max_factor = max_factor > x ? max_factor : x;
            return;
        }
        ll p = x;
        while (p >= x) p = PRho(x);
        while ((x % p == 0)) x /= p;
        fac(x);
        fac(p);
    }

    ll divide(ll n) {
        srand((unsigned) time(0));
        max_factor = 0;
        fac(n);
        return max_factor;
    }
}
namespace DLP {
    const int N = 1111111;

    ll fastpow(ll a, ll n) { //快速幂
        ll res = 1;
        while (n > 0) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }

    ll fastpow(ll a, ll n, ll p) { //针对特别大的数的快速幂
        ll res = 1;
        a %= p;
        while (n > 0) {
            if (n & 1) res = (__int128) res * a % p;
            a = (__int128) a * a % p;
            n >>= 1;
        }
        return res;
    }

    int prime[N], ptot;
    bool ispr[N];
    struct pt {
        ll p;
        int c;
    };

    void getprime() { //获取10^6以内的质数
        memset(ispr, 1, sizeof(ispr));
        for (int i = 2; i < N; ++i) {
            if (ispr[i]) prime[++ptot] = i;
            for (int j = 1; j <= ptot && prime[j] <= (N - 1) / i; ++j) {
                ispr[i * prime[j]] = 0;
                if (!i % prime[j]) break;
            }
        }
    }

    bool cmp(pt x, pt y) {
        return x.p < y.p;
    }

    void findorg(vector<pt> &v, ll num) { //num分解质因数
        while (num >= N) {   //大于10^6的部分，每次用Pho-Rho算法找出最大的一个质因子，然后除掉即可
            ll maxf = PhoRho::divide(num);
            int cnt = 0;
            while (num % maxf == 0) {
                cnt++;
                num = num / maxf;
            }
            v.push_back((pt) {maxf, cnt});
        }
        if (ptot == 0) getprime();
        for (int i = 1; i <= ptot && prime[i] <= num; ++i) { //剩下的就是不大于10^6的质因子了，直接暴力枚举
            if (num % prime[i] == 0) {
                int cnt = 0;
                while (num % prime[i] == 0) {
                    cnt++;
                    num /= prime[i];
                }
                v.push_back((pt) {prime[i], cnt});
            }
        }
        if (num > 1) v.push_back((pt) {num, 1});
        sort(v.begin(), v.end(), cmp);
    }

    int getorg(ll p, ll phi, vector<pt> &v) { //获取ord
        for (int k = 2;; k++) {
            int flag = 1;
            for (int i = 0; i < (int) v.size(); ++i) {
                if (fastpow(k, phi / v[i].p, p) == 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return k;
        }
    }

    ll BSGS(ll a, ll b, ll p, ll mod) { //BSGS模板
        a %= mod;
        b %= mod;
        if (b == 1) return 0;
        if (a == 0) {
            if (b == 0) return 1;
            else return -1;
        }
        ll t = 1;
        int m = int(sqrt(1.0 * p) + 1);
        ll base = b;
        unordered_map<ll, ll> vis;
        for (int i = 0; i < m; ++i) {
            vis[base] = i;
            base = (__int128) base * a % mod;
        }
        base = fastpow(a, m, mod);
        ll now = t;
        for (int i = 1; i <= m + 1; ++i) {
            now = (__int128) now * base % mod;
            if (vis.count(now)) return i * m - vis[now];
        }
        return -1;
    }

    ll getksi(ll g, ll h, ll p, ll c, ll n, ll mod) {  //得到合并后的解集，然后上BSGS
        vector<ll> pi;
        ll tp = 1;
        for (int i = 0; i <= c; ++i) {
            pi.push_back(tp);
            tp *= p;
        }
        ll gq = fastpow(g, pi[c - 1], mod);
        ll inv = 0;
        tp = 1;
        for (int i = c - 1; i >= 0; --i) {
            ll tx = tp * BSGS(gq, fastpow((__int128) h * fastpow(g, pi[c] - inv, mod) % mod, pi[i], mod), p, mod);
            inv += tx;
            tp *= p;
        }
        return inv;
    }

    ll exgcd(ll a, ll b, ll &x, ll &y) { //exgcd模板
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }

    ll getinv(ll a, ll p) { //扩欧求逆元
        if (a == 0) return 1;
        ll x, y;
        exgcd(a, p, x, y);
        return (x % p + p) % p;
    }

    ll gcd(ll x, ll y) { //gcd
        if (x % y == 0) return y;
        return gcd(y, x % y);
    }

    ll ExgcdSolve(ll a, ll b, ll c, ll &x, ll &y) { //求解exgcd
        ll d;
        if (c % (d = gcd(a, b))) return -1;
        a /= d;
        b /= d;
        c /= d;
        exgcd(a, b, x, y);
        x = (__int128) x * c % b;
        while (x <= 0) x += b;
        return x;
    }

    ll crt(vector<ll> ksi, vector<pt> v) { //crt
        int sz = v.size();
        ll M = 1, ans = 0;
        vector<ll> m;
        for (int i = 0; i < sz; ++i) {
            m.push_back(fastpow(v[i].p, v[i].c));
            M *= m[i];
        }
        for (int i = 0; i < sz; ++i) {
            ll Mi = M / m[i];
            ans = ((__int128) ans + (__int128) Mi * getinv(Mi, m[i]) * ksi[i]) % M;
        }
        if (ans < 0) ans += M;
        return ans;
    }

    ll getx(ll h, ll g, ll N, ll mod, vector<pt> &v) { //获取解集，然后用crt合并
        vector<ll> ksi;
        for (pt tp:v) {
            ll tg = fastpow(g, N / fastpow(tp.p, tp.c), mod);
            ll th = fastpow(h, N / fastpow(tp.p, tp.c), mod);
            ksi.push_back(getksi(tg, th, tp.p, tp.c, N, mod));
        }
        return crt(ksi, v);
    }

    ll solve(ll g, ll h, ll p) { //求解g^x = h(mod p)的最小解
        if (h == 1) return 0;
        ll phiP = p - 1;
        vector<pt> v;
        findorg(v, phiP);
        int rt = getorg(p, phiP, v);
        ll x = getx(g, rt, phiP, p, v);
        ll y = getx(h, rt, phiP, p, v);
        ll a = 0, b = 0;
        if (x == 0) {
            if (y == 0) return 1;
            else if (y == 1) return 0;
            else return -1;
        } else return ExgcdSolve(x, phiP, y, a, b);
    }
};
 */
