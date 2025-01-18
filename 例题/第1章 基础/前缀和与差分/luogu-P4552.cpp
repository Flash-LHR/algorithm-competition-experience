#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

ll a[maxn], b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll q = 0, p = 0;
    for (int i = 2; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
        if (b[i] >= 0)
            q += b[i];
        else
            p += abs(b[i]);
    }
    ll ans = min(q, p) + abs(q - p);
    printf("%lld\n%lld\n", ans, abs(q - p) + 1);
    return 0;
}