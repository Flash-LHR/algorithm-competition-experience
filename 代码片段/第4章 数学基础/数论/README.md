## 快速幂

```c++
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
}
```

## 素数

### 素数判定

```c++
bool checkPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

### 素数筛选

```c++
bool is_prime[maxn];
vector<int> prime;
 
void Eratosthenes(int n) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                if (1LL * i * i <= n) {
                    for (int j = i * i; j <= n; j += i)
                        is_prime[j] = false;
                }
            }
        }
    }
}
```

```c++
const int maxn = 1e6 + 10;
int max_prime[maxn];
 
void getMaxPrime() {
    max_prime[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!max_prime[i]) {
            for (int j = i; j < maxn; j += i) max_prime[j] = i;
        }
    }
}
```

```c++
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
}
```

###  反素数

```c++
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
}
```

## 质因数

```c++
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
    if (n > 1) { 
        fac[cnt] = n;
        num[cnt++]++;
    }
}
```

```c++
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
 
void factorization(int n) {
    if (n == 1) return;
    int p[1005], num[1005], cnt = 0;
    while (n > 1) {
        p[++cnt] = minp[n];
        n /= minp[n];
    }
    int j = 1;
    num[j] = 1;
    for (int i = 2; i <= cnt; i++) {
        if (p[i] == p[i - 1])
            ++num[j];
        else {
            num[++j] = 1;
            p[j] = p[i];
        }
    }
    for (int i = 1; i <= j; i++) {
        printf("%d^%d ", p[i], num[i]);
    }
}
```

## 约数

### 因数分解

```c++
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
}
```

```c++
vector<vector<int>> factor;
 
void get_factor(int n) {
    factor.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            factor[j].push_back(i);
        }
    }
}
```

### GCD

```c++
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

```c++
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
```

```c++
int gcd[maxn][maxn], lcm[maxn][maxn];
 
void init(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (!gcd[i][j]) {
            for (int k = 1; k * i <= n && k * j <= n; k++)
                gcd[k * i][k * j] = k, lcm[k * i][k * j] = i * j * k;
        }
    }
}
```

## 扩展欧几里得

```c++
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}
```

```c++
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
    x0 = (x % s + s) % s; 
    return x0;
}
```

## 乘法逆元

```c++
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
```

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
 
ll inv(ll a, ll p) {
    return qkp(a, p - 2, p);
}
```

```c++
ll inv[maxn];
 
void solve(int n, ll p) {
    inv[1] = 1;
    for(int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
}
```

```c++
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
}
```

## 数论函数

### 欧拉函数

```c++
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
}
```

```c++
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
}
```

```c++
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
}
```

### 莫比乌斯函数

```c++
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
```

### 整除分块

```c++
ll cal(ll n) {
    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (n / l) * (r - l + 1);
    }
    return ans;
}
```

```c++
ll cal(ll n, ll m) {
    ll ans = 0;
    for (ll l = 1, r; l <= min(n, m); l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        ans += (n / l) * (m / l) * (r - l + 1);
    }
    return ans;
}
```

