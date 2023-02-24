#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)80;

ll f[M + 5];

void init() {
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= M; i++) f[i] = f[i - 1] + f[i - 2];
}

void work() {
    int n; scanf("%d", &n);
    printf("%lld\n", f[n]);
}

int main() {
    init();
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}