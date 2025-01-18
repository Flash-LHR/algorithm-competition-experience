#include <bits/stdc++.h>

using namespace std;

double f(int k, int n, int m, double p) {
    return (1.0 * k * n + m) / (1.0 - pow(1.0 - p, k));
}

int main() {
    int T, n, m;
	double p;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        p *= (1e-4);
        int l = 1, r = 0x3f3f3f3f;
        while (l < r) {
            int mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
            if (f(mid1, n, m, p) < f(mid2, n, m, p))
                r = mid2 - 1;
            else
                l = mid1 + 1;
        }
        printf("%.10lf\n", f(l, n, m, p));
    }
    return 0;
}
