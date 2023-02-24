#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int mod = (int)1e9 + 7;

int f[M + 5];

void init() {
    f[1] = 3, f[2] = 9;
    for (int i = 3; i <= M; i++) f[i] = 2ll * (f[i - 1] + f[i - 2]) % mod;
}

void work() {
    int n; scanf("%d", &n);
    printf("%d\n", f[n]);
}

int main() {
    init();
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}