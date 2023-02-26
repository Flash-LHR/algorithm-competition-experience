#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

unordered_map<int, int> fi, se;
unordered_set<int> st;
int minp[maxn], prime[maxn], vis[maxn];
int cnt;

void euler() {
    for (int i = 1; i < maxn; i++) minp[i] = i;
    for (int i = 2; i < maxn; i++) {
        if (minp[i] == i) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

void divide(int n) {
    map<int, int> mp;
    int fac, p, num;
    while (n > 1) {
        fac = minp[n];
        n /= fac;
        mp[fac]++;
    }
    for (auto i : mp) {
        p = i.first, num = i.second;
        vis[p]++, st.insert(p);
        if (!fi.count(p)) {
            fi[p] = num;
            continue;
        }
        if (!se.count(p)) {
            if (num < fi[p]) {
                se[p] = fi[p];
                fi[p] = num;
            } else
                se[p] = num;
            continue;
        }
        if (num <= fi[p]) {
            se[p] = fi[p];
            fi[p] = num;
        } else if (num < se[p]) {
            se[p] = num;
        }
    }
}

ll qkp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    euler();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        divide(x);
    }
    ll ans = 1;
    for (auto p : st) {
        if (vis[p] >= n - 1) {
            if (vis[p] == n - 1)
                ans *= qkp(p, fi[p]);
            else
                ans *= qkp(p, se[p]);
        }
    }
    cout << ans << "\n";
    return 0;
}
