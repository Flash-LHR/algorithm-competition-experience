```c++
const int maxn = 2000 + 5;
int bell[maxn][maxn];
 
void f(int n) {
    bell[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        bell[i][1] = bell[i - 1][i - 1];
        for (int j = 2; j <= i; j++) bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
}
```

```c++
typedef long long ll;
const int maxn = 10000;
const int mod = 1e9 + 7;
 
ll B[maxn];
ll C[maxn][maxn];
ll inv[maxn];
 
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
}
```

