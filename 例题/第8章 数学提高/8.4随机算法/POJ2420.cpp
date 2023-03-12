#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-14;
const double dinf = 1e300;
const double delta = 0.993;
const double T = 100;

struct Point {
  double x, y;

  Point(double a = 0, double b = 0) : x(a), y(b) {}
} p[105];

int n;
Point s;

int dcmp(double d) {
    if (fabs(d) < eps) return 0;
    return d > 0 ? 1 : -1;
}

double dis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double f(Point cur) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dis(cur, p[i]);
    }
    return ans;
}

double SA() {
    double t = T, ans = dinf;
    Point tmp = s;
    while (t > eps) {
        Point nxt(tmp.x + (rand() * 2.0 - RAND_MAX) * t, tmp.y + (rand() * 2.0 - RAND_MAX) * t);
        double res = f(nxt);
        double del = res - ans;
        if (del < 0) {
            ans = res;
            s = tmp = nxt;
        } else if (exp((ans - res) / t) * RAND_MAX > rand()) {
            tmp = nxt;
        }
        t *= delta;
    }
    return ans;
}

void solve() {
    scanf("%d", &n);
    double sumx = 0, sumy = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        sumx += p[i].x, sumy += p[i].y;
    }
    s = Point(sumx / n, sumy / n);
    printf("%.0lf\n", SA());
}

int main() {
    srand(100000007);
    srand(rand()), srand(rand());
    solve();
    return 0;
}
