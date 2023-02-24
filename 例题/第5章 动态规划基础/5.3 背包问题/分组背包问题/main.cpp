#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(1e2);
const int inf = 0x3f3f3f3f;

int f[M + 5];
int v[M + 5], w[M + 5];

void work() {
    int n, V; scanf("%d %d", &n, &V);
    memset(f, -inf, sizeof f);
    f[0] = 0;
    for (int i = 1, s; i <= n; i++) {
        scanf("%d", &s);
        for (int j = 1; j <= s; j++) scanf("%d %d", &v[j], &w[j]);
        for (int j = V; j >= 1; j--) {
            for (int k = 1; k <= s; k++)
                if (j >= v[k]) cmax(f[j], f[j - v[k]] + w[k]);
        }
    }
    printf("%d\n", *max_element(f, f + V + 1));
}

int main() {
    work();
    return 0;
}