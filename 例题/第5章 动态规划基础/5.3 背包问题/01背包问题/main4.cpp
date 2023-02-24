#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e3;
const int inf = 0x3f3f3f3f;

int f[M + 5];

void work() {
    int n, V; scanf("%d %d", &n, &V);
    memset(f, -inf, sizeof f);
    f[0] = 0;
    for (int i = 1, v, w; i <= n; i++) {
        scanf("%d %d", &v, &w);
        for (int j = V; j >= v; j--) f[j] = max(f[j], f[j - v] + w);
    }
    printf("%d\n", *max_element(f, f + V + 1));
}

int main() {
    work();
    return 0;
}