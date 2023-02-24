#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(1e2);
const int inf = 0x3f3f3f3f;

int f[M + 5][M + 5];

void work() {
    int n, V, M; scanf("%d %d %d", &n, &V, &M);
    memset(f, -inf, sizeof f);
    f[0][0] = 0;
    for (int i = 1, v, m, w; i <= n; i++) {
        scanf("%d %d %d", &v, &m, &w);
        for (int j = V - v; j >= 0; j--)
            for (int k = M - m; k >= 0; k--)
                if (f[j][k] >= 0) cmax(f[j + v][k + m], f[j][k] + w);
    }
    int mx = -inf;
    for (int i = 0; i <= V; i++) cmax(mx, *max_element(f[i], f[i] + M + 1));
    printf("%d\n", mx);
}

int main() {
    work();
    return 0;
}