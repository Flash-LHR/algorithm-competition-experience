#include <cstdio>
#include <math.h>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int maxn = 1e4 + 10;

struct BigIntegerFactor {
    const static int maxm = 1e6 + 10;
    ll prime[maxm], p[maxm], sz, cnt;
    ll fac[10010], num[10010];

    inline ll mul(ll a, ll b, ll Mod) {
        ll ans = 0;
        while (b) {
            if (b & 1) ans = (ans + a) % Mod;
            a = (a + a) % Mod;
            b >>= 1;
        }
        return ans;
    }

    void init(int up) {  //传入的参数不能超过maxm,根据数据范围来定,1e5wa了就改1e6试试
        int tot = 0;
        sz = up - 1;
        for (int i = 1; i <= sz; i++) p[i] = i;
        for (int i = 2; i <= sz; i++) {
            if (p[i] == i) prime[tot++] = i;
            for (int j = 0; j < tot && 1LL * i * prime[j] <= sz; j++) {
                p[i * prime[j]] = prime[j];
                if (i % prime[j] == 0) break;
            }
        }
    }

    inline ll qkp(ll x, ll n, ll p) {
        ll ans = 1;
        while (n) {
            if (n & 1) ans = mul(ans, x, p);
            x = mul(x, x, p);
            n >>= 1;
        }
        return ans;
    }


    inline bool check(ll a, ll n) {
        ll t = 0, u = n - 1;
        while (!(u & 1)) t++, u >>= 1;
        ll x = qkp(a, u, n), xx = 0;
        while (t--) {
            xx = mul(x, x, n);
            if (xx == 1 && x != 1 && x != n - 1) return false;
            x = xx;
        }
        return xx == 1;
    }

    inline bool miller(ll n, ll k) {  //检测一个数n是否为素数,一般k取20即可
        if (n == 2) return true;
        if (n < 2 || !(n & 1)) return false;
        if (n <= sz) return p[n] == n;
        for (int i = 0; i <= k; i++) {
            if (!check(rand() % (n - 1) + 1, n)) return false;
        }
        return true;
    }

    inline ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    inline ll Abs(ll x) {
        return x < 0 ? -x : x;
    }

    inline ll Pollard_rho(ll n) {
        ll s = 0, t = 0, c = rand() % (n - 1) + 1, v = 1, ed = 1;
        while (1) {
            for (int i = 1; i <= ed; i++) {
                t = (mul(t, t, n) + c) % n;
                v = mul(v, Abs(t - s), n);
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

    void getfactor(ll n) {  //得到有重复的质因子
        if (n <= sz) {
            while (n != 1) fac[cnt++] = p[n], n /= p[n];
            return;
        }
        if (miller(n, 6)) fac[cnt++] = n;
        else {
            ll d = n;
            while (d >= n) d = Pollard_rho(n);
            getfactor(d);
            getfactor(n / d);
        }
    }

    void print(ll x) {   //打印"质因子-个数"
        cnt = 0;
        getfactor(x);
        int k = 1;
        num[0] = 1;
        sort(fac, fac + cnt);
        for (int i = 1; i < cnt; i++) {
            if (fac[i] == fac[i - 1])
                num[k - 1]++;
            else {
                num[k] = 1;
                fac[k++] = fac[i];
            }
        }
        cnt = k;
        for (int i = 0; i < cnt; i++)
            printf("%lld %lld\n", fac[i], num[i]);
    }

    void solve(ll x, ll &tot) {  //进行其他操作
        cnt = 0;
        getfactor(x);
        ll k = 1;
        num[0] = 1;
        sort(fac, fac + cnt);
        for (int i = 1; i < cnt; i++) {
            if (fac[i] == fac[i - 1])
                num[k - 1]++;
            else {
                num[k] = 1;
                fac[k++] = fac[i];
            }
        }
        cnt = tot = k;
    }

} Q;

ll fac[maxn], num[maxn];
ll g, l, res, ansa, ansb, sum, tot;

ll qkp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(ll a, ll b, ll deep) {
    if (a * g + b * g > sum) return;
    if (deep == tot) {
        if (sum > a * g + b * g) {
            sum = a * g + b * g;
            ansa = a * g, ansb = b * g;
        }
        return;
    }
    dfs(a * fac[deep], b, deep + 1);
    dfs(a, b * fac[deep], deep + 1);
}

int main() {
    Q.init(100000);
    while (~scanf("%lld%lld", &g, &l)) {
        if (g == l) {
            printf("%lld %lld\n", g, l);
            continue;
        }
        res = l / g;
        Q.solve(res, tot);
        memcpy(fac, Q.fac, sizeof Q.fac);
        memcpy(num, Q.num, sizeof Q.num);
        for (int i = 0; i < tot; i++)
            fac[i] = qkp(fac[i], num[i]);
        sum = 1e18;
        dfs(1LL, 1LL, 0);
        if (ansa > ansb) swap(ansa, ansb);
        printf("%lld %lld\n", ansa, ansb);
    }
    return 0;
}
