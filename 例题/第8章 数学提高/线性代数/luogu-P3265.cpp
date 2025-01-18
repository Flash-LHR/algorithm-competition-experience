#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
const double eps = 1e-8;
const int maxn = 2e5 + 10;
 
int n, m, ans, cnt;
ld b[510][510];
 
struct node {
  int w;
  ld a[510];
 
  bool operator<(const node &p) const {
      return w < p.w;
  }
} c[510];
 
//直接消元也是正确的
//void guass() {
//    for (int i = 1; i <= n; i++) {
//        int temp = i;
//        for (int j = i + 1; j <= n; j++)
//            if (fabs(a[j][i]) >= eps && w[j] < w[temp]) {
//                temp = j;
//            }
//        if (fabs(a[temp][i]) < eps) continue;
//        if (temp != i) {
//            for (int j = 1; j <= m; j++) swap(a[i][j], a[temp][j]);
//            swap(w[i], w[temp]);
//        }
//        ans += w[i], cnt++;
//        for (int j = m; j >= i; j--) a[i][j] /= a[i][i];
//        for (int j = i + 1; j <= n; j++) {
//            for (int k = m; k >= i; k--) {
//                a[j][k] -= a[j][i] * a[i][k];
//            }
//        }
//        for (int j = i + 1; j <= m; j++) {
//            for (int k = n; k >= i; k--) {
//                a[k][j] -= a[i][j] * a[k][i];
//            }
//        }
//    }
//}
 
bool insert(ld *x) {
    for (int i = 1; i <= m; i++) {
        if (fabs(x[i]) < eps) continue;
        if (fabs(b[i][i]) < eps) {
            for (int j = i; j <= m; j++) b[i][j] = x[j];
            return 1;
        }
        ld k = x[i] / b[i][i];
        for (int j = i; j <= m; j++) x[j] -= k * b[i][j];
    }
    return 0;
}
 
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%Lf", &c[i].a[j]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i].w);
//    guass();
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (insert(c[i].a)) {
            cnt++;
            ans += c[i].w;
        }
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}
