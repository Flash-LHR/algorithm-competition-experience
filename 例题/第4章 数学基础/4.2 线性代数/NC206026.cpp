#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
const int Mod = 998244353;
const int maxn = 2e5 + 10;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
const int N = 1e5 + 10;

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
int gao(VI &a, ll n) {
    VI c = BM(a);
    c.erase(c.begin());
    rep(i, 0, SZ(c)) c[i] = (Mod - c[i]) % Mod;
    return solve(n, c, VI(a.begin(), a.begin() + SZ(c)));
}
};   // namespace linear_seq

ll f[maxn];

void init() {
    f[1] = f[2] = 1;
    for (int i = 3; i < N; i++) f[i] = (f[i - 1] + f[i - 2]) % Mod;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;
    init();
    cin >> n >> k;
    vector<int> g(N);
    g[0] = 0;
    for (int i = 1; i < N; i++) g[i] = (g[i - 1] + powMOD(i, k) * f[i] % Mod) % Mod;
    int ans = linear_seq::gao(g, n);
    cout << ans << "\n";
    return 0;
}
