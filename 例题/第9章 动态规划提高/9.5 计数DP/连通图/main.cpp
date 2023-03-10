#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(T n) {
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) print(n / 10);
    putchar(n % 10 + '0');
}

template <typename T>
void print(T n, char ch) {
    print(n), putchar(ch);
}

typedef __int128 ll;

const int M = 50;
const int N = M * M;

int n;
ll c[M + 5][M + 5];
ll f[M + 5];

void init() {
    c[0][0] = 1;
    for (int i = 1; i <= M; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    f[1] = 1;
    for (int i = 2; i <= M; i++) {
        f[i] = (ll(1)<<(i*(i-1)/2));
        for (int j = 1; j < i; j++)
            f[i] -= f[j] * c[i - 1][j - 1] * (ll(1)<<((i-j)*(i-j-1)/2));
    }
}

int main() {
    init();
    while (~scanf("%d", &n) && n) print(f[n], '\n');
    return 0;
}