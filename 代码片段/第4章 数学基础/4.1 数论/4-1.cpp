#include <bits/stdc++.h>

using namespace std;

/*
判断素数朴素算法
bool checkPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
} */

/*
埃氏筛
const int maxn = 1e6 + 10;
int prime[maxn];
bool is_prime[maxn];
int p;

int Eratosthenes(int n) {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime[p++] = i;
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i 的倍数开始
                    is_prime[j] = false;   // i的倍数标记为合数
        }
    }
    return p;
} */

/*
最大质因数表
const int maxn = 1e6 + 10;
int max_prime[maxn];

void getMaxPrime() {
    max_prime[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!max_prime[i]) {
            for (int j = i; j < maxn; j += i) max_prime[j] = i;
        }
    }
} */

/*
线性筛
int cnt, prime[maxn];
bool vis[maxn];

void euler(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && 1ll * i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
} */

/*
求最小非负整数x使得其因数个数为n
int prime[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int n;
unsigned long long ans;

void dfs(int deep, int limit, unsigned long long cur, int num) {
    if (num > n) return;
    if (num == n && ans > cur) {
        ans = cur;
        return;
    }
    for (int i = 1; i <= limit; i++) {
        if (ans / prime[deep] < cur || num * (i + 1) > n)
            break;   // 剪枝：不超过当前答案最小值且因数个数不超过n
        cur *= prime[deep];
        if (n % (num * (i + 1)) == 0)   // 剪枝：只有当前因数整除n才能继续搜
            dfs(deep + 1, i, cur, num * (i + 1));
    }
} */

/*
求[1,n]中因数最多的数
ll n, ans;
int cnt;
int prime[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void dfs(int deep, int num, int limit, ll cur) {
    if (cur > n || deep >= 16) return;
    if (num > cnt) {
        cnt = num;
        ans = cur;
    }
    if (num == cnt && ans > cur) ans = cur;
    for (int i = 1; i <= limit; i++) {
        if (n / prime[deep] < cur) break;
        cur *= prime[deep];
        dfs(deep + 1, num * (i + 1), i, cur);
    }
} */

/*
反素数表算法
int Map[maxn], d[maxn];

void init() {
    for (int i = 1; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) d[j]++;
        if (!Map[d[i]]) Map[d[i]] = i;
    }
} */

/*
// 因数分解朴素算法
vector<int> factor;

void getFactor(int n) {
    factor.clear();
    for (int i = 1; 1ll * i * i <= n; i++)
        if (n % i == 0) {
            if (i * i == n)
                factor.push_back(i);
            else {
                factor.push_back(i);
                factor.push_back(n / i);
            }
        }
} */

/*
欧几里得算法
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
} */

/*
最小公倍数算法
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
} */

/*
// 质因数分解朴素算法
int fac[maxn], num[maxn];
int cnt;

void solve(int n) {
    int m = sqrt(n + 0.5);
    memset(num, 0, sizeof num);
    for (int i = 2; i <= m && n != 1; i++) {
        if (n % i == 0) {
            fac[cnt] = i;
            while (n % i == 0) {
                num[cnt]++;
                n /= i;
            }
            cnt++;
        }
    }
    if (n > 1) {   // 最后
        fac[cnt] = n;
        num[cnt++]++;
    }
} */

/*
线性复杂度的质因数分解
vector<int> prime;
int minp[maxn];

void euler() {
    for (int i = 1; i < maxn; i++) minp[i] = i;
    for (int i = 2; i < maxn; i++) {
        if (minp[i] == i) prime.push_back(i);
        for (int j = 0; j < prime.size() && 1LL * i * prime[j] < maxn; j++) {
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

void divide(int n) {
    if (n == 1) return;
    int p[1005], num[1005], cnt = 0, k = 1;
    while (n > 1) {
        p[++cnt] = minp[n];
        n /= minp[n];
    }
    sort(p + 1, p + cnt + 1);
    num[1] = 1;
    for (int i = 2; i <= cnt; i++) {
        if (p[i] == p[i - 1])
            num[k]++;
        else {
            num[++k] = 1;
            p[k] = p[i];
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d^%d ", p[i], num[i]);
    }
} */

/*
慢速乘（俄罗斯农民乘法）
typedef long long ll;

ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    x %= p;
    while(n) {
        if (n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
} */

/*
快速乘
long long mul(long long a, long long b, long long m) {
    unsigned long long c =
        (unsigned long long)a * b - (unsigned long long)((long double)a / m * b + 0.5L) * m;
    if (c < m) return c;
    return c + m;
} */

/*
扩展欧几里得算法
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}
*/

/*
扩展欧几里得求解线性同余方程
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

int solve(int a, int b, int p) {
    if (b % gcd(a, p)) return -1;
    int x, y, r, x0;
    r = exgcd(a, p, x, y);
    int s = p / r;
    x = x * b / r;
    x0 = (x % s + s) % s;   // 最小整数解
    return x0;
} */

/*
扩展欧几里得求逆元
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
} */

/*
快速幂取模求逆元
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

ll inv(ll a, ll p) {
    return qkp(a, p - 2, p);
} */

/*
打出[1,n]的逆元表
ll inv[maxn];

void solve(int n, ll p) {
    inv[1] = 1;
    for(int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
} */

/*
ll fac[maxn], inv[maxn];

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

// 求1!-n!的所有逆元
void solve(int n, ll p) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    inv[n] = qkp(fac[n], p - 2, p);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
} */

/*
求单个数的欧拉函数
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
} */

/*
埃氏筛法求欧拉函数
int phi[maxn];

void phi_table(int n) {
    memset(phi, 0, sizeof phi);
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        if (!phi[i]) {
            for (int j = i; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
} */

/*
欧拉筛法求欧拉函数
vector<int> prime;
bitset<maxn> vis;
int phi[maxn];

void euler() {
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            phi[i] = i - 1;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            } else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
} */

/*
整除分块
ll cal(ll n, ll k) {
    ll ans = 0;
    for (ll l = 1, r; l <= k; l = r + 1) {
        r = n / (n / l);
        if (r > k) r = k;
        ans += (n / l) * (r - l + 1);
    }
    return ans;
} */

/*
二维整除分块
ll cal(ll n, ll m) {
    ll ans = 0;
    ll up = min(n, m);
    for (ll l = 1, r; l <= up; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        if (r > up) r = up;
        //...
    }
    return ans;
}
 */

/*
扩展欧拉定理模板
ll a[maxn];
map<ll, ll> mp;

ll Mod(ll x, ll p) {
    return x > p ? x % p + p : x;
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

ll mul(ll a, ll b, ll p) {   // 如果模数过大则采用慢速乘
    ll ans = 0;
    while (b) {
        if (b & 1) ans = Mod(ans + a, p);
        a = Mod(a + a, p);
        b >>= 1;
    }
    return ans;
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

ll cal(int i, ll p) {   // cal(1, p)
    if (i == n || p == 1) return Mod(a[l], p);
    return qkp(a[i], cal(i + 1, getphi(p)), p);
} */
int main() {
    return 0;
}