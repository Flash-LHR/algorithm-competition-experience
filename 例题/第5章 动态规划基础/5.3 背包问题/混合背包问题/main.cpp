#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(2e4);
const int inf = 0x3f3f3f3f;

int n, V;
int f[M + 5];
int q[M + 5], l, r;

void zeroOne(int v, int w) {
    for (int j = V - v; j >= 0; j--) if (f[j] >= 0) cmax(f[j + v], f[j] + w);
}

void complete(int v, int w) {
    for (int j = 0; j <= V - v; j++) if (f[j] >= 0) cmax(f[j + v], f[j] + w);
}

void multiple(int v, int w, int s) {
    for (int j = 0; j < v; j++) {   
        l = 1, r = 0;
        int mx = (V - j) / v;
        for (int k = mx - 1; k >= max(0, mx - s); k--) {
            while (l <= r && f[j + q[r] * v] - q[r] * w 
                <= f[j + k * v] - k * w) r--;
            q[++r] = k;
        }
        for (int k = mx; k >= 1; k--) {
            if (l <= r && q[l] == k) l++;
            cmax(f[j + k * v], f[j + q[l] * v] + (k - q[l]) * w);
            if (k - s - 1 >= 0) {
                while (l <= r && f[j + q[r] * v] - q[r] * w 
                    <= f[j + (k - s - 1) * v] - (k - s - 1) * w) r--;
                q[++r] = k - s - 1;
            }
        }
    }
}

void work() {
    scanf("%d %d", &n, &V);
    memset(f, -inf, sizeof f);
    f[0] = 0;
    for (int i = 1, v, w, s; i <= n; i++) {
        scanf("%d %d %d", &v, &w, &s);
        if (s == -1) zeroOne(v, w);
        else if (s == 0) complete(v, w);
        else multiple(v, w, s);
    }
    printf("%d\n", *max_element(f, f + V + 1));
}

int main() {
    work();
    return 0;
}