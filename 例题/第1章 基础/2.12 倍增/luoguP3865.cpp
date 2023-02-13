#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;

int n, m;
int a[maxn], Log[maxn], d[maxn][20];

void init() {
    for (int i = 2; i <= n; i++) Log[i] = Log[i / 2] + 1;

    for (int i = 1; i <= n; i++) d[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j - 1) <= n; i++) {
            d[i][j] = max(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
        }
    }
}

int main() {
    int l, r;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    init();
    while (m--) {
        scanf("%d%d", &l, &r);
        int k = Log[r - l + 1];
        printf("%d\n", max(d[l][k], d[r - (1 << k) + 1][k]));
    }
    return 0;
}