#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int maxn = 5e4 + 10;

vector<int> prime;
bitset<maxn> vis;
int mu[maxn], premu[maxn], a[maxn];
ll d[maxn];

void init() {
    mu[1] = d[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime.push_back(i);
            mu[i] = -1, a[i] = 1, d[i] = 2;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) {
                mu[i * prime[j]] = -mu[i];
                d[i * prime[j]] = d[i] * 2, a[i * prime[j]] = 1;
            } else {
                mu[i * prime[j]] = 0;
                d[i * prime[j]] = d[i] / (a[i] + 1) * (a[i] + 2), a[i * prime[j]] = a[i] + 1;
                break;
            }
        }
    }
    for (int i = 1; i < maxn; i++) {
        premu[i] = premu[i - 1] + mu[i];
        d[i] += d[i - 1];
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n, m;
    cin >> t;
    init();
    while (t--) {
        cin >> n >> m;
        int up = min(n, m);
        ll ans = 0;
        for (int l = 1, r; l <= up; l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            if (r > up) r = up;
            ans += (premu[r] - premu[l - 1]) * d[n / l] * d[m / l];
        }
        cout << ans << "\n";
    }
    return 0;
}
