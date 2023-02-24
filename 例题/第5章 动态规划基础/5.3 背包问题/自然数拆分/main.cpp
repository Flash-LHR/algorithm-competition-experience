#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = int(4e3);
const ll mod = 2147483648ll;

ll f[M + 5];

void work() {
    int n; scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) if (f[j]) (f[j + i] += f[j]) %= mod;
    }
    printf("%lld\n", f[n] - 1);
}

int main() {
    work();
    return 0;
}