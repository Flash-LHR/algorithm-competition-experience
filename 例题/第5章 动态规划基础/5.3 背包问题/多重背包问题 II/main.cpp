#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = (int)2e3;
const int inf = 0x3f3f3f3f;

int f[M + 5];

void work() {
    int n, V; scanf("%d %d", &n, &V);
    memset(f, -inf, sizeof f);
    f[0] = 0;
    for (int i = 0, v, w, s; i < n; i++) {
        scanf("%d %d %d", &v, &w, &s);
        vector<int> cnt;
        for (int i = 1; i <= s; i <<= 1) cnt.push_back(i), s -= i;
        if (s) cnt.push_back(s);
        for (const int &x: cnt) {
            for (int j = V - x * v; j >= 0; j--)
                if (f[j] >= 0) cmax(f[j + x * v], f[j] + x * w);
        }
    }
    printf("%d\n", *max_element(f, f + V + 1));
}

int main() {
    work();
    return 0;
}