#include <bits/stdc++.h>
using namespace std;

#define double long double
#define int long long
#define endl "\n"
const int max_n = 1e5 + 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n, m, p;
double qm(double b, int po) {
    double res = 1;
    while (po) {
        if (po & 1) res = res * b;
        po >>= 1;
        b = b * b;
    }
    return res;
}

double get(int x) {
    return (n * x + m) * 1.0 / (1 - qm((1 - (p * 1e-4)), x));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        double ans = inf;
        int l = 0, r = inf;
        int cnt = 100;
        while (cnt--) {
            int m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
            double t1 = get(m1), t2 = get(m2);
            if (t1 >= t2)
                l = m1;
            else
                r = m2;
            ans = min(t1, t2);
        }
        for (int i = l; i <= r; i++) ans = min(ans, get(i));
        cout << fixed << ans << endl;
    }

    return 0;
}
