/*
递推求解组合数
ll cal(int n, int m) {
    ll ans = 1;
    for (int i = 1; i <= m; i++) ans = ans * (n - i + 1) / i;
    return ans;
} */

/*
杨辉三角求组合数
ll C[1005][1005];
const int Mod = 1e9 + 7;

void cal() {
    C[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j <= (i >> 1); j++) {
            C[i][j] = C[i][i - j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
        }
    }
} */

/*
递归求解斐波那契数列
int Fibonacci(int n){
    return n > 2 ? Fibonacci(n - 1) + Fibonacci(n - 2) : 1;
} */

/*
递推求解斐波那契数列
int F[maxn];
int num;
void Fibonacci() {
    F[1] = F[2] = 1;
    for (int i = 3; i <= num; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
} */

/*
快速倍增法求解斐波那契数列
typedef long long ll;
typedef pair<ll, ll> pii;
const int Mod = 1e9 + 7;

pii fib(ll n) {
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1);
    ll c = (2 * p.second % Mod - p.first + Mod) % Mod * p.first % Mod;
    ll d = (p.first * p.first % Mod + p.second * p.second % Mod) % Mod;
    if (n & 1) return {d, c + d};
    else return {c, d};
} */

/*
递推法求解卡特兰数
ll f[1005];

void katelan(int n) {
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++) {
            f[i] += (f[j] * f[i - 1 - j]) % Mod;
            f[i] %= Mod;
        }
} */

/*
组合数法求卡特兰数
ll C[1005][1005];

ll katelan(int n) {
    C[0][0] = 1;
    for (int i = 1; i < 1005; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j <= (i >> 1); j++) {
            C[i][j] = C[i][i - j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
        }
    }
    return (C[2 * n][n] - C[2 * n][n - 1] + Mod) % Mod;   // 不要忘记减法的取模
} */

/*
线性求解卡特兰数
ll f[maxn], inv[maxn];

void katelan(int n, int p) {
    f[2] = inv[1] = 1LL;
    for (int i = 2; i < n + 2; i++) inv[i] = (p - p / i) * inv[p % i] % p;
    for (int i = 2; i < n + 2; i++) f[i + 1] = (4 * i - 6) * f[i] % p * inv[i] % p;
} */

/*
递推求贝尔数
const int maxn = 2000 + 5;
int bell[maxn][maxn];

void f(int n) {
    bell[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        bell[i][1] = bell[i - 1][i - 1];
        for (int j = 2; j <= i; j++) bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
} */
/*
求伯努利数
typedef long long ll;
const int maxn = 10000;
const int mod = 1e9 + 7;
ll B[maxn];         // 伯努利数
ll C[maxn][maxn];   // 组合数
ll inv[maxn];       // 逆元（计算伯努利数）

void init() {
    // 预处理组合数
    for (int i = 0; i < maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int k = 1; k < i; k++) {
            C[i][k] = (C[i - 1][k] % mod + C[i - 1][k - 1] % mod) % mod;
        }
    }
    // 预处理逆元
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    // 预处理伯努利数
    B[0] = 1;
    for (int i = 1; i < maxn; i++) {
        ll ans = 0;
        if (i == maxn - 1) break;
        for (int k = 0; k < i; k++) {
            ans += C[i + 1][k] * B[k];
            ans %= mod;
        }
        ans = (ans * (-inv[i + 1]) % mod + mod) % mod;
        B[i] = ans;
    }
} */
