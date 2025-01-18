#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
        }
    for (int i = 1, j = n + 1; i <= n; i++, j++) a[i][j] = 1;
    bool ok = gauss_jordan(n, 2 * n);
    if (!ok) {
        puts("No Solution");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = n + 1; j <= 2 * n; j++) {
            printf("%lld%c", a[i][j], j == 2 * n ? '\n' : ' ');
        }
    return 0;
}