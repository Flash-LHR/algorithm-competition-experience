#include <bits/stdc++.h>

using namespace std;

/*
矩阵及初等变换
struct Matrix {
    int n, m;
    int matrix[505][505];

    Matrix() {}

    Matrix(int x, int y) {
        n = x, m = y;
        memset(matrix, 0, sizeof(matrix));
    }
};

Matrix add(Matrix a, Matrix b) {
    Matrix ans;
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= a.m; j++) ans.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j]) % Mod;
    return ans;
}

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
} */

/*
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
} */

/*
高斯消元
const double eps = 1e-8;
double a[1005][1005];
int n;

bool gauss() {
    for (int i = 1; i < n; i++) {
        int temp = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[j][i]) > fabs(a[temp][i])) temp = j;
        // 如果当前列的最大值仍然为0，无解
        if (fabs(a[temp][i]) < eps) return false;
        // 与最大主元所在行交换
        if (temp != i) {
            for (int j = i; j <= n + 1; j++) swap(a[i][j], a[temp][j]);
        }
        double p;
        for (int j = i + 1; j <= n; j++) {   // 消元
            p = a[j][i] / a[i][i];
            for (int k = i; k <= n + 1; k++) a[j][k] -= a[i][k] * p;
        }
    }
    // 回代求解
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
    return true;
} */

/*
高斯-约旦消元法
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
} */

/*
高斯消元判断解的情况
int n;
double a[105][105];

int guass() {
    int r = 1;
    for (int c = 1; c <= n; c++) {
        int temp = r;
        for (int i = r + 1; i <= n; i++) {
            if (fabs(a[i][c]) > fabs(a[temp][c])) temp = i;   // 每行第一个非零元素越大误差越小
        }
        if (fabs(a[temp][c]) < eps) continue;   // 这步是实现行列异步的关键
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
                return -1;   // 无解
            else
                return 0;   // 无穷解
        }
    }
    // 有唯一解，回代求解
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
    return 1;
} */

/*
异或高斯消元写法1
int a[maxn], ans[maxn];

int xor_guass() {
    int r = 1;
    for (int c = n; c >= 1; c--) {
        int temp = r;
        for (int i = r; i <= n; i++)
            if ((a[i] >> c) & 1) {
                temp = i;
                break;
            }
        if (!((a[temp] >> c) & 1)) continue;
        swap(a[r], a[temp]);
        for (int i = r + 1; i <= n; i++) {
            if ((a[i] >> c) & 1) a[i] ^= a[r];
        }
        r++;
    }
    if (r <= n) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) return -1;
            if (a[i] == 0) return 1 << (n - i + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        int res = a[i] & 1;
        for (int j = i - 1; j; j--)
            res ^= ((a[i] >> j) & 1) * ans[j];
        ans[i] = res;
    }
    return 1;
}
*/

/*
异或高斯消元写法2
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
            ans[c] = 1;   // 固定将自由变元取1
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
} */

/*
const int Mod = 1e9 + 7;

ll a[505][1005];

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

void print(int n,int m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            printf("%lld%c", a[i][j], j == 2 * n ? '\n' : ' ');
        }
}

bool gauss_jordan(int n, int m) {
    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = i;
        while (!a[tmp][i] && tmp <= n) tmp++;
        if (tmp == n + 1) return false;
        for (int j = 1; j <= m; j++)
            swap(a[i][j], a[tmp][j]);
        ll p = a[i][i], inv = qkp(a[i][i], Mod - 2, Mod);
        for (int j = 1; j <= m; j++)
            a[i][j] = a[i][j] * inv % Mod;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                ll q = a[j][i];
                for (int k = 1; k <= m; k++)
                    a[j][k] = (a[j][k] - q * a[i][k] % Mod + Mod) % Mod;
            }
        }
        //print(n,m);
    }
    return true;
} */
/*
#define rep(i, a, n) for (int i = a; i < n; i++)
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
const int N = ? ;   // 传入多少项这里设置

ll powMOD(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mod)
        if (b & 1) ans = ans * a % Mod;
    return ans;
}

namespace linear_seq {
ll res[N], base[N], _c[N], _md[N];

vector<int> Md;

void mul(ll *a, ll *b, int k) {
    rep(i, 0, k + k) _c[i] = 0;
    rep(i, 0, k) if (a[i]) rep(j, 0, k) _c[i + j] = (_c[i + j] + a[i] * b[j]) % Mod;
    for (int i = k + k - 1; i >= k; i--)
        if (_c[i])
            rep(j, 0, SZ(Md)) _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % Mod;
    rep(i, 0, k) a[i] = _c[i];
}

int solve(ll n, VI a, VI b) {
    ll ans = 0, pnt = 0;
    int k = SZ(a);
    assert(SZ(a) == SZ(b));
    rep(i, 0, k) _md[k - 1 - i] = -a[i];
    _md[k] = 1;
    Md.clear();
    rep(i, 0, k) if (_md[i] != 0) Md.push_back(i);
    rep(i, 0, k) res[i] = base[i] = 0;
    res[0] = 1;
    while ((1ll << pnt) <= n) pnt++;
    for (int p = pnt; p >= 0; p--) {
        mul(res, res, k);
        if ((n >> p) & 1) {
            for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i];
            res[0] = 0;
            rep(j, 0, SZ(Md)) res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % Mod;
        }
    }
    rep(i, 0, k) ans = (ans + res[i] * b[i]) % Mod;
    if (ans < 0) ans += Mod;
    return ans;
}

VI BM(VI s) {
    VI C(1, 1), B(1, 1);
    int L = 0, m = 1, b = 1;
    rep(n, 0, SZ(s)) {
        ll d = 0;
        rep(i, 0, L + 1) d = (d + (ll)C[i] * s[n - i]) % Mod;
        if (d == 0)
            ++m;
        else if (2 * L <= n) {
            VI T = C;
            ll c = Mod - d * powMOD(b, Mod - 2) % Mod;
            while (SZ(C) < SZ(B) + m) C.pb(0);
            rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % Mod;
            L = n + 1 - L;
            B = T;
            b = d;
            m = 1;
        } else {
            ll c = Mod - d * powMOD(b, Mod - 2) % Mod;
            while (SZ(C) < SZ(B) + m) C.pb(0);
            rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % Mod;
            ++m;
        }
    }
    return C;
}

int gao(VI &a, ll n) {   // 调用这个函数，传入打表前几项的vector，返回答案(默认对int数取模答案为int)
    VI c = BM(a);
    c.erase(c.begin());
    rep(i, 0, SZ(c)) c[i] = (Mod - c[i]) % Mod;
    return solve(n, c, VI(a.begin(), a.begin() + SZ(c)));
}

};   // namespace linear_seq */
/*
#include <bits/stdc++.h>

#define rep(i, a, b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const ll N = 25;
const ll mo = 1e9 + 7;

//快速幂
ll fpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1)ans = ans * a % mo;
        b >>= 1;
        a = a * a % mo;
    }
    return ans;
}

//BM算法 求线性递推数列的递推公式
vector<ll> BM(const vector<ll> &s) {
    vector<ll> C = {1}, B = {1}, T;
    ll L = 0, m = 1, b = 1;
    rep(n, 0, s.size() - 1) {
        ll d = 0;
        rep(i, 0, L)d = (d + s[n - i] % mo * C[i]) % mo;
        if (d == 0)m++;
        else {
            T = C;
            ll t = mo - fpow(b, mo - 2) * d % mo;
            while (C.size() < B.size() + m)C.push_back(0);
            rep(i, 0, B.size() - 1)C[i + m] = (C[i + m] + t * B[i]) % mo;
            if (2 * L > n)m++;
            else L = n + 1 - L, B = T, b = d, m = 1;
        }
    }
    return C;
}

//矩阵快速幂求解数列单项值,s为初值,C为递推公式
ll MatrixSolve(const vector<ll> &s, const vector<ll> &C, ll n) {
    if (n < s.size())return s[n];
    ll k = C.size() - 1, b = n - k + 1;
    static ll B[N][N], t[N], a[N], c[N][N];
    rep(i, 0, k - 1)a[i] = s[i];
    rep(i, 0, k - 1)rep(j, 0, k - 1)B[i][j] = j == 0 ? ((C[i + 1] > 0) * mo - C[i + 1]) : (i == j -
1); while (b) { if (b & 1) { rep(i, 0, k - 1)t[i] = 0; rep(i, 0, k - 1)rep(j, 0, k - 1)t[i] = (t[i]
+ a[k - j - 1] * B[j][k - i - 1]) % mo; rep(i, 0, k - 1)a[i] = t[i];
        }
        b >>= 1;
        rep(i, 0, k - 1)rep(j, 0, k - 1)c[i][j] = 0;
        rep(r, 0, k - 1)rep(j, 0, k - 1)if (B[r][j])rep(i, 0, k - 1)c[i][j] = (c[i][j] + B[i][r] *
B[r][j]) % mo; rep(i, 0, k - 1)rep(j, 0, k - 1)B[i][j] = c[i][j];
    }
    return a[k - 1];
}

//更快的矩阵快速幂求解数列单项值,s为初值,C为递推公式
ll fastMatrixSolve(const vector<ll> &s, const vector<ll> &C, ll n) {
    if (n < s.size())return s[n];
    ll k = C.size() - 1, b = n - k + 1;
    static ll B[N][N][64], t[N], a[N], c[N][N], init_flag = 1;
    if (init_flag) {
        init_flag = 0;
        rep(i, 0, k - 1)rep(j, 0, k - 1)B[i][j][0] = j == 0 ? ((C[i + 1] > 0) * mo - C[i + 1]) : (i
== j - 1); for (ll it = 1; it < 64; it++) { rep(i, 0, k - 1)rep(j, 0, k - 1)B[i][j][it] = 0; rep(r,
0, k - 1) rep(j, 0, k - 1) if (B[r][j][it - 1]) rep(i, 0, k - 1) B[i][j][it] = (B[i][j][it] +
B[i][r][it - 1] * B[r][j][it - 1]) % mo;
        }
    }
    rep(i, 0, k - 1)a[i] = s[i];
    ll it = 0;
    while (b) {
        if (b & 1) {
            rep(i, 0, k - 1)t[i] = 0;
            rep(i, 0, k - 1)rep(j, 0, k - 1)t[i] = (t[i] + a[k - j - 1] * B[j][k - i - 1][it]) % mo;
            rep(i, 0, k - 1)a[i] = t[i];
        }
        b >>= 1;
        it++;
    }
    return a[k - 1];
}

//牛顿多项式插值
class NewtonPoly {
public:
    ll f[N], d[N], x[N], n = 0;

    void add(ll X, ll Y) {
        x[n] = X, f[n] = Y % mo;
        rep(i, 1, n)f[n - i] = (f[n - i + 1] - f[n - i]) % mo * fpow((x[n] - x[n - i]) % mo, mo - 2)
% mo; d[n++] = f[0];
    }

    ll operator()(ll X) const {
        ll ans = 0, t = 1;
        rep(i, 0, n - 1)ans = (ans + d[i] * t) % mo, t = (X - x[i]) % mo * t % mo;
        return ans + mo * (ans < 0);
    }
};

//检验线性递推数列的通项公式是否为多项式,C为递推公式
bool polyCheck(const vector<ll> &C) {
    ll m = mo - C[1], last = 1;
    rep(i, 1, C.size() - 1) {
        last = last * (m - i + 1) % mo * fpow(i, mo - 2) % mo;
        if (last != (i & 1 ? (mo - C[i]) : C[i]))return false;
    }
    return true;
}

//矩阵
class intMatrix {
public:
    ll a[N][N], n, m;

    bool operator<(const intMatrix &b) const {
        rep(i, 0, n - 1)rep(j, 0, m - 1)if (a[i][j] != b.a[i][j])return a[i][j] < b.a[i][j];
        return false;
    }

    bool operator==(const intMatrix &b) const {
        return !(*this < b) && !(b < *this);
    }

    static intMatrix Eye(ll n) {
        intMatrix c;
        c.n = c.m = n;
        rep(i, 0, n - 1)rep(j, 0, n - 1)c.a[i][j] = i == j;
        return c;
    }

    intMatrix operator*(const intMatrix &b) const {
        assert(m == b.n);
        intMatrix c;
        c.n = n, c.m = b.m;
        rep(i, 0, c.n - 1)rep(j, 0, c.m - 1)c.a[i][j] = 0;
        rep(i, 0, c.n - 1)rep(j, 0, c.m - 1)rep(k, 0, m - 1)c.a[i][j] = (c.a[i][j] + a[i][k] *
b.a[k][j]) % mo; return c;
    }

    intMatrix operator^(int t) const {
        assert(n == m);
        intMatrix c = Eye(n), b = *this;
        while (t) {
            if (t & 1)c = c * b;
            b = b * b;
            t >>= 1;
        }
        return c;
    }

    void print() const {
        rep(i, 0, n - 1)rep(j, 0, m - 1)cout << a[i][j] << " \n"[j == m - 1];
        cout << endl;
    }
};

//求同余意义下不依赖初值的周期,C为递推公式,d为步长
ll periodSolve(const vector<ll> &C, ll d) {
    static map<intMatrix, ll> tab;
    tab.clear();
    ll k = C.size() - 1;
    assert(C[k] != 0);
    intMatrix A, B, T = intMatrix::Eye(k), D = T;
    A.n = A.m = B.n = B.m = k;
    rep(i, 0, k - 1)rep(j, 0, k - 1)A.a[i][j] = j == 0 ? ((C[i + 1] > 0) * mo - C[i + 1]) : (i == j
- 1); rep(i, 0, k - 1)rep(j, 0, k - 1)B.a[i][j] = j == k - 1 ? ((mo - C[i]) * fpow(C[k], mo - 2) %
mo) : (i == j + 1); rep(i, 1, d) { T = T * B; if (T == D)return i; tab[T] = i;
    }
    intMatrix Ad = A ^d;
    ll x = 0;
    while (1) {
        if (tab.find(D) != tab.end())return x * d + tab[D];
        D = D * Ad;
        x++;
    }
    return -1;
}

ll polySolve(const vector<ll> &s, const vector<ll> &C, ll n) {
    if (n < s.size())return s[n];
    static ll g[N], f[N], d[N];
    ll k = (ll) C.size() - 1, w = 1;
    rep(i, 0, k)f[i] = i == 1, d[i] = i == k ? 1 : C[k - i];
    while ((w << 1) <= n)w <<= 1;
    while (w >>= 1) {
        rep(i, 0, k + k - 2)g[i] = 0;
        rep(i, 0, k - 1)if (f[i])rep(j, 0, k - 1)(g[i + j] += f[i] * f[j]) %= mo;
        for (ll i = k + k - 2; i >= k; i--)if (g[i])rep(j, 1, k)(g[i - j] -= g[i] * d[k - j]) %= mo;
        rep(i, 0, k - 1)f[i] = g[i];
        if (w & n)
            for (ll i = k; i >= 0; i--)
                f[i] = i == k ? f[i - 1] : (i == 0 ? -f[k] * d[i] : (f[i - 1] - f[k] * d[i])) % mo;
    }
    ll ans = 0;
    rep(i, 0, k - 1)(ans += f[i] * s[i]) %= mo;
    return ans + (ans < 0) * mo;
}

class Sequence {
public:
    ll poly;
    vector<ll> A, C;
    NewtonPoly P;

    void build(const vector<ll> &s) {
        A = s;
        C = BM(A);
        poly = polyCheck(C);
        if (poly)rep(i, 0, s.size() - 1)P.add(i, s[i]);
    }

    ll operator()(ll n) const {
        return poly ? P(n) : polySolve(A, C, n);
    }

    friend ostream &operator<<(ostream &o, const Sequence &b) {
        o << "f(n)";
        rep(i, 1, b.C.size() - 1)o << "+(" << b.C[i] << ")*f(n-" << i << ")";
        o << "=0 (mod " << mo << ")";
        return o;
    }

    ll period() const {
        ll M = periodSolve(C, (ll) sqrt(mo)), ans = M;
        return M;
        for (ll i = 1; i * i <= M; i++)
            if (M % i == 0) {
                ll d = i, flag = 1;
                rep(i, 0, (ll) C.size() - 2)if ((*this)(d + i) != A[i])flag = 0;
                if (flag)ans = min(ans, d);
                d = M / i, flag = 1;
                rep(i, 0, (ll) C.size() - 2)if ((*this)(d + i) != A[i])flag = 0;
                if (flag)ans = min(ans, d);
            }
        return ans;
    }
} F;

int main() {
    ios::sync_with_stdio(false);
    F.build({1, 1, 2, 3, 5, 8, 13, 21});
    cout << F << endl;
    F.build({0,1,4,9,16,25,36,49});
    cout<<F<<endl;
    F.build({0,1,5,15,35,70,126,210,330,495,715});
    cout<<F<<endl;
    F.build({0,1,2,0,1,2,0,1,2});
    F.build({4,14,52,194,724,2702,10084,37634});
    cout<<F<<endl;
    return 0;
} */

int main() {
    return 0;
}