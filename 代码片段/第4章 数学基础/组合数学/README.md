## 排列组合

```c++
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
}
```

## 常见数列

```c++
int F[maxn];
int num;
void Fibonacci() {
    F[1] = F[2] = 1;
    for (int i = 3; i <= num; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}
```

```c++
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
}
```

