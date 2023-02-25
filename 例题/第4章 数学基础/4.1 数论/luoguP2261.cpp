#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e5 + 10;

ull n, k;

ull cal() {
    ull ans = 0;
    for (ull l = 1, r; l <= n; l = r + 1) {
        if (k / l)
            r = min(k / (k / l), n);
        else
            r = n;
        ans += (k / l) * (r - l + 1) * (l + r) / 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cout << n * k - cal() << endl;
    return 0;
}
