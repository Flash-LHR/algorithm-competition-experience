#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int Mod = 20101009;
const int maxn = 1e7 + 10;

ll sum[maxn], F[maxn];
bitset<maxn> vis;
vector<int> prime;

void init() {
    sum[1] = F[1] = 1;
    vis.reset(), prime.clear();
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime.push_back(i);
            F[i] = (1 - i + Mod);
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) {
                F[i * prime[j]] = (F[i] * F[prime[j]]) % Mod;
            } else {
                F[i * prime[j]] = F[i];
                break;
            }
        }
        sum[i] = (sum[i - 1] + F[i] * i % Mod) % Mod;
    }
}

ll f(ll x) {
    return x * (x + 1) / 2 % Mod;
}

ll solve(ll n, ll m) {
    ll up = min(n, m), ans = 0;
    for (ll l = 1, r; l <= up; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        if (r > up) r = up;
        ans += (sum[r] - sum[l - 1] + Mod) % Mod * f(n / l) % Mod * f(m / l) % Mod;
        ans %= Mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    init();
    cin >> n >> m;
    cout << solve(n, m) << "\n";
    return 0;
}
