#include <bits/stdc++.h>
using namespace std;

const int M = int(1e4);

int f[M + 5];

void work() {
    int n, m; scanf("%d %d", &n, &m);
    f[0] = 1;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        for (int j = m - a; j >= 0; j--) if (f[j]) f[j + a] += f[j];
    }
    printf("%d\n", f[m]);
}

int main() {
    work();
    return 0;
}