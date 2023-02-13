#include <iostream>

using namespace std;
const double eps = 1e-6;
const int maxn = 2e5 + 10;

int n, f;
int a[maxn];
double b[maxn];

bool check(double x) {
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i] - x;
    double sum = 1e9, ans = -1e9;
    for (int i = f; i <= n; i++) {
        sum = min(sum, b[i - f]);
        ans = max(ans, b[i] - sum);
    }
    return ans >= 0;
}

int main() {
    cin >> n >> f;
    for (int i = 1; i <= n; i++) cin >> a[i];
    double l = 1e-6, r = 1e9;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    int ans = (l + eps) * 1000;
    printf("%d\n", ans);
    return 0;
}