#include <bits/stdc++.h>
using namespace std;

int f[11][2];
int num[11];

int dfs(int pos, bool pre, bool lim) {
    if (pos == -1) return 1;
    if (!lim && ~f[pos][pre]) return f[pos][pre];
    int up = (lim ? num[pos] : 9), res = 0;
    for (int i = 0; i <= up; i++) {
        if (i == 4 || (pre && i == 2)) continue;
        res += dfs(pos - 1, i == 6, lim && i == up);
    }
    if (!lim) f[pos][pre] = res;
    return res;
}

int cal(int n) {
    if (n == 0) return 1;
    int pos = 0;
    while (n) {
        num[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1, false, true);
}

int main() {
    memset(f, -1, sizeof f);
    int l, r;
    while (~scanf("%d %d", &l, &r) && l + r)    
        printf("%d\n", cal(r) - cal(l - 1));
    return 0;
}