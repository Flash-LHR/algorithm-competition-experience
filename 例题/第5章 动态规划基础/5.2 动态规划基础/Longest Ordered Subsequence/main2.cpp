#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = (int)1e3;

int n, a[M + 5];
int f[M + 5];

int lis() {
    int m = 0;
    f[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > f[m]) f[++m] = a[i];
        else f[lower_bound(f + 1, f + m + 1, a[i]) - f] = a[i];
    }
    return m;
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d\n", lis());
}

int main() {
    work();
    return 0;
}