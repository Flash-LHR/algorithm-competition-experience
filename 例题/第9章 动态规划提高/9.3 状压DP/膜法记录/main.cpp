#include <bits/stdc++.h>
using namespace std;

const int M = 20;
const int N = int(1e5);

char s[M + 5][N + 5];
int cnt[1<<M];

void work() {
    int n, m, a, b; scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    memset(cnt, 0, sizeof(cnt[0]) * (1<<n));
    for (int j = 0; j < m; j++) {
        int state = 0;
        for (int i = 0; i < n; i++) state = state * 2 + (s[i][j] == '*');
        cnt[state]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1<<n); j++) if (j >> i & 1) cnt[j] += cnt[j ^ (1<<i)];
    }
    for (int i = 0; i < (1<<n); i++) {
        if (__builtin_popcount(i) <= a && m - cnt[i] <= b) {
            puts("yes");
            return;
        }
    }
    puts("no");
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}