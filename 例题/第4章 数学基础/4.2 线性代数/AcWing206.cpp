#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

struct Matrix {
    int n, m;
    ll a[65][65];

    Matrix() {}

    Matrix(int x, int y) {
        n = x, m = y;
        memset(a, 0, sizeof a);
    }

    Matrix operator*(const Matrix &p) const {
        Matrix ret(n, p.m);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= p.m; j++)
                for (int k = 0; k <= m; k++) ret.a[i][j] += a[i][k] * p.a[k][j];
        return ret;
    }
} t[65];

Matrix qkp(Matrix mx, int q) {
    Matrix ans(mx.n, mx.m);
    for (int i = 0; i <= ans.n; i++) ans.a[i][i] = 1;
    while (q) {
        if (q & 1) ans = ans * mx;
        mx = mx * mx;
        q >>= 1;
    }
    return ans;
}

string s[15];
int b[10][10];
int n, m, num, cnt, tot;

inline int ID(int p, int q) {
    return n * (p - 1) + q;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> num >> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> s[0];
        for (int j = 1; j <= s[0].size(); j++) {
            b[i][j] = s[0][j - 1] - '0';
        }
    }
    for (int i = 0; i < cnt; i++) cin >> s[i];
    tot = 1;
    for (int i = 0; i < cnt; i++) tot = lcm(tot, (int)s[i].size());
    for (int i = 0; i < cnt; i++) {
        int x = tot / (int)s[i].size();
        string res = "";
        for (int j = 1; j <= x; j++) res += s[i];
        s[i] = res;
    }
    Matrix G(n * m, n * m);
    for (int i = 0; i <= n * m; i++) G.a[i][i] = 1;
    for (int k = 1; k <= tot; k++) {   // 求出每秒的转移矩阵
        t[k].n = t[k].m = n * m, t[k].a[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char ch = s[b[i][j]][k - 1];
                if (ch >= '0' && ch <= '9')
                    t[k].a[0][ID(i, j)] = ch - '0', t[k].a[ID(i, j)][ID(i, j)] = 1;
                else if (ch == 'N' && i > 1)
                    t[k].a[ID(i, j)][ID(i - 1, j)] = 1;
                else if (ch == 'S' && i < n)
                    t[k].a[ID(i, j)][ID(i + 1, j)] = 1;
                else if (ch == 'W' && j > 1)
                    t[k].a[ID(i, j)][ID(i, j - 1)] = 1;
                else if (ch == 'E' && j < m)
                    t[k].a[ID(i, j)][ID(i, j + 1)] = 1;
            }
        G = G * t[k];
    }
    int x = num / tot, y = num % tot;
    Matrix F(0, n * m);
    F.a[0][0] = 1;
    G = qkp(G, x);
    F = F * G;
    for (int k = 1; k <= y; k++) F = F * t[k];
    ll ans = 0;
    for (int i = 1; i <= n * m; i++) ans = max(ans, F.a[0][i]);
    cout << ans << "\n";
    return 0;
}
