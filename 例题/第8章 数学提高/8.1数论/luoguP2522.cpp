#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int maxn = 5e4 + 10;

int mu[maxn], k;
vector<int> prime;
bitset<maxn> vis;

void init() {
    mu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) {
                mu[i * prime[j]] = -mu[i];
            } else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
        mu[i] += mu[i - 1];
    }
}

ll cal(int n, int m) {
    int up = min(n, m);
    ll ans = 0;
    for (int l = 1, r; l <= up; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        if (r > up) r = up;
        ans += 1LL * (mu[r] - mu[l - 1]) * (n / (k * l)) * (m / (k * l));
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, a, b, c, d;
    init();
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> k;
        cout << cal(b, d) - cal(a - 1, d) - cal(b, c - 1) + cal(a - 1, c - 1) << "\n";
    }
    return 0;
}
