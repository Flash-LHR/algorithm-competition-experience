#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;

double f(double x, double y) {
    return 6.0 * pow(x, 7.0) + 8.0 * pow(x, 6.0) + 7.0 * pow(x, 3.0) + 5.0 * pow(x, 2.0) - y * x;
}

double solve(double k) {
    double l = 0, r = 100.0, midl, midr;
    while (r - l > eps) {
        midl = l + (r - l) / 3;
		midr = r - (r - l) / 3;
        if (f(midl, k) < f(midr, k)) {
            r = midr;
        } else {
			l = midl;
		}
    }
    return f(l, k);
}

int main() {
    int T;
    double y;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &y);
        printf("%.4lf\n", solve(y));
    }
    return 0;
}

