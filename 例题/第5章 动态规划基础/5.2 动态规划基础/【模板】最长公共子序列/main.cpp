#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n;
int id[M + 5], a[M + 5];
int f[M + 5];

int lis() {
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (f[m] < a[i]) f[++m] = a[i];
        else f[upper_bound(f + 1, f + m + 1, a[i]) - f] = a[i];
    }
    return m;
}

void work() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), id[x] = i;
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[i] = id[x];
    printf("%d\n", lis());
}

int main() {
    work();
    return 0;
}