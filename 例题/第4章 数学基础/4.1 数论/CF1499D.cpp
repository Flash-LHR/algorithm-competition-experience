#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e7 + 10;

int num[maxn];
bitset<maxn> vis;

void init() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            num[i] = 1;
            for (int j = i + i; j < maxn; j += i) {
                vis[j] = 1;
                num[j]++;
            }
        }
    }
}

vector<int> fac;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    int c, d, x;
    init();
    cin >> T;
    while (T--) {
        cin >> c >> d >> x;
        fac.clear();
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                int j = x / i;
                if (i == j)
                    fac.push_back(i);
                else
                    fac.push_back(i), fac.push_back(j);
            }
        }
        ll ans = 0;
        for (auto g : fac) {
            int sum = d + x / g;
            if (sum % c) continue;
            ans += 1LL << num[sum / c];
        }
        cout << ans << "\n";
    }
    return 0;
}
