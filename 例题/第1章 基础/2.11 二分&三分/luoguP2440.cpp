#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int n, k;
int a[maxn];

bool check(int x) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] / x;
    }
    return ans >= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    if (check(ans))
        cout << ans << endl;
    else
        cout << 0 << endl;
    return 0;
}