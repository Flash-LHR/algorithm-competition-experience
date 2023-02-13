#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r1 = 1, r2 = 1;
    ll ans = 0;
    while (l <= n) {
        while (r1 <= n && a[r1] - a[l] < k) ++r1;
        while (r2 <= n && a[r2] - a[l] <= k) ++r2;
        if (a[r1] - a[l] < k) break;
        ans += r2 - r1;
        l++;
    }
    cout << ans << "\n";
    return 0;
}