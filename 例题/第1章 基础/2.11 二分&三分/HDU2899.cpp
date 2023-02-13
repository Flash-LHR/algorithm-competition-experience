#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 2e5 + 10;

double f(double x, double y) {
    return 6.0 * pow(x, 7.0) + 8.0 * pow(x, 6.0) + 7.0 * pow(x, 3.0) + 5.0 * pow(x, 2.0) - y * x;
}

int dcmp(double d) {
    if (fabs(d) < eps) return 0;
    return d > 0 ? 1 : -1;
}

double tri_search(double k) {
    double l = 0, r = 100.0, midl, midr;
    while (r - l > eps) {
        midl = l + (r - l) / 3, midr = r - (r - l) / 3;
        if (dcmp(f(midl, k) - f(midr, k)) < 0) {
            r = midr;
        } else
            l = midl;
    }
    return f(midl, k);
}

int main() {
    int T;
    double y;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &y);
        printf("%.4lf\n", tri_search(y));
    }
    return 0;
}
