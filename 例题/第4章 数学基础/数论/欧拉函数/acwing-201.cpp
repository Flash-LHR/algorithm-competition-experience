#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1005;

vector<int> prime;
bitset<maxn> vis;
int phi[maxn];

void euler() {
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            phi[i] = i - 1;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            } else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
    for (int i = 2; i < maxn; i++) phi[i] += phi[i - 1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, N;
    cin >> T;
    euler();
    for (int k = 1; k <= T; k++) {
        cin >> N;
        cout << k << " " << N << " " << 3 + 2 * (phi[N] - 1) << "\n";
    }
    return 0;
}
