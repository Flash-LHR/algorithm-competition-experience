#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(1e2);
const int N = int(1e1);
const int inf = 0x3f3f3f3f;

int a[M + 5];
char s[N + 5];
vector<int> v;
int cnt[1<<N];
int f[2][1<<N][1<<N];

void work() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) a[i] = a[i] * 2 + (s[j] == 'P');
    }
    for (int i = 0; i < (1<<m); i++) {
        if ((i&(i>>1)) || (i&(i>>2))) continue;
        v.push_back(i);
        cnt[i] = __builtin_popcount(i);
    }
    if (n == 1) {
        int mx = -inf;
        for (const int &i: v) if ((i && a[0]) == i) cmax(mx, cnt[i]);
        return printf("%d\n", mx), void();
    }
    for (const int &i: v) if ((i & a[0]) == i) {
        for (const int &j: v)
            if ((j & a[1]) == j && !(i & j)) f[1][i][j] = cnt[i] + cnt[j];
    }
    for (int i = 1, u; i < n - 1; i++) {
        u = i & 1;
        for (const int &j: v) for (const int &k: v) f[u ^ 1][j][k] = -inf;
        for (const int &j: v) {
            for (const int &k: v) if (f[u][j][k] >= 0) {
                for (const int &l: v)   
                    if ((l & a[i + 1]) == l && !(l & j) && !(l & k))
                    cmax(f[u ^ 1][k][l], f[u][j][k] + cnt[l]);
            }
        }
    }
    int mx = -inf;
    for (const int &i: v) for (const int &j: v) cmax(mx, f[(n - 1) & 1][i][j]);
    printf("%d\n", mx);
}

int main() {
    work();
    return 0;
}