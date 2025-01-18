## 矩阵及初等变换

```c++
struct Matrix {
    int n, m;
    int matrix[505][505];
 
    Matrix() {}
 
    Matrix(int x, int y) {
        n = x, m = y;
        memset(matrix, 0, sizeof(matrix));
    }
};
```

```c++
Matrix add(Matrix a, Matrix b) {
    Matrix ans;
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= a.m; j++) ans.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j]) % Mod;
    return ans;
}
```

```c++
Matrix mul(Matrix a, Matrix b) {
    Matrix ans(a.n, b.m);
    for (int i = 1; i <= ans.n; i++) {
        for (int j = 1; j <= ans.m; j++)
            for (int k = 1; k <= a.m; k++) {
                ans.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j] % Mod;
                ans.matrix[i][j] %= Mod;
            }
    }
    return ans;
}
 
Matrix qkp(Matrix mx, ll n) {
    Matrix ans(mx.n, mx.m);
    for (int i = 1; i <= mx.n; i++) ans.matrix[i][i] = 1;
    while (n) {
        if (n & 1) ans = mul(ans, mx);
        mx = mul(mx, mx);
        n >>= 1;
    }
    return ans;
}
```

## 矩阵快速幂

```c++
typedef long long ll;
const int Mod = 1e9 + 7;
 
struct Matrix {
    ll matrix[10][10];
    int n, m;
 
    Matrix() {}
 
    Matrix(int x, int y) {
        n = x, m = y;
        memset(matrix, 0, sizeof(matrix));
    }
};
 
Matrix mul(Matrix a, Matrix b) {
    Matrix ans(a.n, b.m);
    for (int i = 1; i <= ans.n; i++)
        for (int j = 1; j <= ans.m; j++)
            for (int k = 1; k <= a.m; k++) {
                ans.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j] % Mod;
                ans.matrix[i][j] %= Mod;
            }
    return ans;
}
 
Matrix qkp(Matrix mx, ll n) {
    Matrix ans(mx.n, mx.m);
    for (int i = 1; i <= mx.n; i++) ans.matrix[i][i] = 1;
    while (n) {
        if (n & 1) ans = mul(ans, mx);
        mx = mul(mx, mx);
        n >>= 1;
    }
    return ans;
}
 
ll solve(ll x) {
    if (x == 1 || x == 2) return 1;
    Matrix a(2, 2);
    a.matrix[1][1] = 1, a.matrix[1][2] = 1;
    a.matrix[2][1] = 1, a.matrix[2][2] = 0;
    Matrix b(2, 1);
    b.matrix[1][1] = 1, b.matrix[2][1] = 1;
    Matrix ans = mul(qkp(a, x - 2), b);
    return ans.matrix[1][1];
}
```

## 高斯消元

```c++
const double eps = 1e-8;
double a[1005][1005];
int n;
 
bool gauss() {
    for (int i = 1; i < n; i++) {
        int temp = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[j][i]) > fabs(a[temp][i])) temp = j;
        if (fabs(a[temp][i]) < eps) return false;
        if (temp != i) {
            for (int j = i; j <= n + 1; j++) swap(a[i][j], a[temp][j]);
        }
        double p;
        for (int j = i + 1; j <= n; j++) {
            p = a[j][i] / a[i][i];
            for (int k = i; k <= n + 1; k++) a[j][k] -= a[i][k] * p;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
    return true;
}
```

```c++
const double eps = 1e-8;
double a[1005][1005];
 
bool gauss_jordan(int n) {
    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = i;
        while (fabs(a[tmp][i]) < eps && tmp <= n) tmp++;
        if (tmp == n + 1) return false;
        for (int j = 1; j <= n + 1; j++) swap(a[i][j], a[tmp][j]);
        double p = a[i][i];
        for (int j = 1; j <= n + 1; j++) a[i][j] = a[i][j] / p;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                double q = a[j][i];
                for (int k = 1; k <= n + 1; k++) a[j][k] -= q * a[i][k];
            }
        }
    }
    return true;
}
```

```c++
int n;
double a[105][105];
 
int guass() {
    int r = 1;
    for (int c = 1; c <= n; c++) {
        int temp = r;
        for (int i = r + 1; i <= n; i++) {
            if (fabs(a[i][c]) > fabs(a[temp][c])) temp = i;
        }
        if (fabs(a[temp][c]) < eps) continue;
        for (int j = c; j <= n + 1; j++) swap(a[r][j], a[temp][j]);
        for (int j = n + 1; j >= c; j--) a[r][j] /= a[r][c];
        for (int i = r + 1; i <= n; i++) {
            for (int j = n + 1; j >= c; j--)
                if (fabs(a[i][c]) >= eps) {
                    a[i][j] -= a[i][c] * a[r][j];
                }
        }
        r++;
    }
    if (r <= n) {
        for (int i = 1; i <= n; i++) {
            bool ok = 0;
            for (int j = 1; j <= n; j++)
                if (fabs(a[i][j]) > eps) ok = 1;
            if (ok) continue;
            if (fabs(a[i][n + 1]) >= eps)
                return -1;
            else
                return 0;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
    return 1;
}
```

```c++
int ans[maxn], n;
bitset<maxn> a[maxn];
 
bool xor_guass() {
    int r = 1;
    for (int c = 1; c <= n; c++) {
        int temp = r;
        for (int i = r; i <= n; i++) {
            if (a[i][c]) {
                temp = i;
                break;
            }
        }
        if (!a[temp][c]) {
            ans[c] = 1;
            continue;
        }
        if (temp != r) swap(a[r], a[temp]);
        for (int i = r + 1; i <= n; i++) {
            if (a[i][c]) a[i] ^= a[r];
        }
        r++;
    }
    if (r <= n) {
        for (int i = n; i >= 1; i--) {
            if (!a[i].count()) continue;
            int pos = a[i]._Find_first(), res = a[pos][n + 1];
            if (pos == n + 1) return 0;
            for (int j = pos + 1; j <= n; j++) {
                res ^= a[i][j] * ans[j];
            }
            ans[pos] = res;
        }
    } else {
        for (int i = n; i >= 1; i--) {
            int res = a[i][n + 1];
            for (int j = i + 1; j <= n; j++) res ^= a[i][j] * ans[j];
            ans[i] = res;
        }
    }
    return 1;
}
```

