#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}

int main() {
    ll a, b, c, x1, y1, mi_x, mi_y, ma_x, ma_y, cnt;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        ll g = gcd(a, b);
        if (c % g != 0) {
            puts("-1");
        } else {
            exgcd(a, b, x1, y1);
            ll x = x1 * c / g, y = y1 * c / g;
            a /= g, b /= g;
            if (x > 0 && y <= 0) {
                ll dx = x / b - (x % b == 0), dy = abs(y) / a + 1;
                if (dx >= dy) {
                    cnt = dx - dy + 1;
                    mi_x = x - dx * b, mi_y = y + dy * a;
                    ma_x = x - dy * b, ma_y = y + dx * a;
                    printf("%lld %lld %lld %lld %lld\n", cnt, mi_x, mi_y, ma_x, ma_y);
                } else {
                    mi_x = x - dx * b, mi_y = y + dy * a;
                    printf("%lld %lld\n", mi_x, mi_y);
                }
            } else if (x <= 0 && y > 0) {
                ll dx = abs(x) / b + 1, dy = y / a - (y % a == 0);
                if (dy >= dx) {
                    cnt = dy - dx + 1;
                    mi_x = x + dx * b, mi_y = y - dy * a;
                    ma_x = x + dy * b, ma_y = y - dx * a;
                    printf("%lld %lld %lld %lld %lld\n", cnt, mi_x, mi_y, ma_x, ma_y);
                } else {
                    mi_x = x + dx * b, mi_y = y - dy * a;
                    printf("%lld %lld\n", mi_x, mi_y);
                }
            } else {
                ll dx = x / b - (x % b == 0), dy = y / a - (y % a == 0);
                cnt = dx + dy;
                mi_x = x - dx * b, mi_y = y - dy * a;
                ma_x = x + dy * b, ma_y = y + dx * a;
                printf("%lld %lld %lld %lld %lld\n", cnt, mi_x, mi_y, ma_x, ma_y);
            }
        }
    }

    return 0;
}
