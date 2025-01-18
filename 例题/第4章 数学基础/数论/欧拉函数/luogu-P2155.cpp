#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e7 + 10;

vector<int> prime;
ll fac[maxn], inv[maxn], ans[maxn], Mod;
bitset<maxn> vis;

void euler() {
    vis.reset();
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void init(ll p) {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        if (i != p)
            fac[i] = (fac[i - 1] * i) % p;
        else
            fac[i] = fac[i - 1];
    }
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    ans[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (vis[i])
            ans[i] = ans[i - 1];
        else {
            if (i != p)
                ans[i] = (i - 1) * inv[i] % p * ans[i - 1] % p;
            else
                ans[i] = (i - 1) * ans[i - 1] % p;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, m;
    euler();
    cin >> t >> Mod;
    init(Mod);
    while (t--) {
        cin >> n >> m;
        if (n >= Mod && m < Mod) {
            cout << "0\n";
            continue;
        }
        cout << fac[n] * ans[m] % Mod << "\n";
    }
    return 0;
}
