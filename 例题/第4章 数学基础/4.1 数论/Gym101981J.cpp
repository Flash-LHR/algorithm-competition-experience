#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int prime[maxn], minp[maxn], all[maxn];
vector<int> fac[maxn], pos[maxn];
bitset<maxn> vis;
int cnt, tot;

void euler() {
    for (int i = 1; i <= maxn; i++) minp[i] = i;
    for (int i = 2; i < maxn; i++) {
        if (minp[i] == i) {
            prime[++cnt] = i;
            pos[i].push_back(0);
        }
        for (int j = 1; j <= cnt && 1LL * i * prime[j] < maxn; j++) {
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

void divide(int idx, int n) {
    tot = 0;
    while (n != 1) {
        all[tot++] = minp[n];
        n /= minp[n];
    }
    sort(all, all + tot);
    int m = unique(all, all + tot) - all;
    for (int i = 0; i < m; i++) {
        pos[all[i]].push_back(idx);
        vis[all[i]] = 1;
    }
}

inline ll cal(ll x) {
    return x * (x + 1) / 2;
}

bool ok = 0;

ll solve(int p) {
    ll ans = 0;
    for (int i = 1, l, r; i < pos[p].size(); i++) {
        l = pos[p][i - 1] + 1, r = pos[p][i] - 1;
        if (l <= r) ans += cal(r - l + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    euler();
    vis.reset();
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        divide(i, x);
    }
    int num = vis.count();
    ll ans = cal(n) * num;
    for (int i = 1; i <= cnt; i++) {
        if (vis[prime[i]]) {
            pos[prime[i]].push_back(n + 1);
            ll res = solve(prime[i]);
            ans -= res;
        }
    }
    cout << ans << "\n";
    return 0;
}
