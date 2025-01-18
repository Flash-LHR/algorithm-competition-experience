#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int tot;
bool vis[maxn];
int p[maxn], num[maxn];
vector<int> prime, factor;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void euler() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && 1LL * i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void factorization(ll x) {
    tot = 0;
    ll y = x;
    for (auto pm : prime) {
        if (1LL * pm * pm > y) break;
        if (x % pm == 0) {
            p[++tot] = pm;
            num[tot] = 0;
            while (x % pm == 0) {
                ++num[tot];
                x /= pm;
            }
        }
    }
    if (x > 1) p[++tot] = x, num[tot] = 1;
}

void dfs(int d, long long cur = 1) {
    if (d == tot + 1) {
        factor.push_back(cur);
        return;
    }
    for (int i = 0; i <= num[d]; i++) {
        dfs(d + 1, cur);
        cur *= p[d];
    }
}

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int n;
    ll a, b, c, d;
    cin >> n;
    euler();
    while (n--) {
        cin >> a >> c >> b >> d;
        factorization(d);
        factor.clear();
        dfs(1);
        int ans = 0;
        for (auto x : factor) {
            if (gcd(a, x) == c && lcm(b, x) == d) {
                ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
