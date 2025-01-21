#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e6 + 10;

vector<int> prime, ans;
bool is_prime[maxn], vis[maxn];

void euler() {
    int m = sqrt(INT_MAX + 0.5);
    prime.clear();
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && 1LL * i * prime[j] <= m; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve(ll l, ll r) {
    memset(vis, true, sizeof(vis));
    if (l == 1) l++;
    for (int i = 0; i < prime.size() && 2LL * prime[i] <= r; i++) {
        if (prime[i] < l) {
            ll x = l / prime[i], L;
            if (x * prime[i] < l)
                L = (x + 1) * prime[i];
            else
                L = x * prime[i];
            for (ll j = L; j <= r; j += prime[i]) vis[j - l] = 0;
        } else {
            for (ll j = 2LL * prime[i]; j <= r; j += prime[i]) vis[j - l] = 0;
        }
    }
    ans.clear();
    for (int i = 0; i <= r - l; i++)
        if (vis[i]) ans.push_back(i + l);
    cout << ans.size() << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, r;
    euler();
    cin >> l >> r;
    solve(l, r);
    return 0;
}
