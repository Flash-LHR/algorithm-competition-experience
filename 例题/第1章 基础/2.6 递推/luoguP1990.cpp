#include <iostream>

using namespace std;
typedef long long ll;
const int Mod = 10000;
const int maxn = 1e6 + 10;

ll f[maxn], sum[maxn];

int main() {
    int n;
    cin >> n;
    f[0] = 1, f[1] = 1, f[2] = 2;
    sum[0] = 1, sum[1] = 2, sum[2] = 4;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i] + f[i - 1]) % Mod;
        f[i] = (f[i] + f[i - 2]) % Mod;
        f[i] = (f[i] + sum[i - 3] * 2) % Mod;
        sum[i] = (sum[i - 1] + f[i]) % Mod;
    }
    cout << f[n] << endl;
    return 0;
}