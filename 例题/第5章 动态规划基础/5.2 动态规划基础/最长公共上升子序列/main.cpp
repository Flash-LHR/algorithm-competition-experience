#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e3;
const int inf = 0x3f3f3f3f;

int n, a[M + 5], b[M + 5];
int f[M + 5][M + 5];

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = mx + 1;
            if (a[i] > b[j]) mx = max(mx, f[i - 1][j]);
        }
    }
    printf("%d\n", *max_element(f[n] + 1, f[n] + n + 1));
}

/*
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        f[i][j] = f[i - 1][j];
        if (a[i] == b[j]) {
            for (int k = 0; k < j; k++)
                if (b[k] < a[i]) f[i][j] = max(f[i][j], f[i - 1][k] + 1);
        }
    }
}
*/

int main() {
    work();
    return 0;
}