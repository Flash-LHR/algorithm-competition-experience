#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;

int n, a[M + 5], id[M + 5];
int sl[M + 5], sr[M + 5];

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
    sort(id + 1, id + n + 1, [&](int x, int y) {
        if (a[x] != a[y]) return a[x] < a[y];
        return x < y;
    });
    int sc = 0;
    for (int l = 1, r = 0; l <= n; l = r + 1) {
        while (r + 1 <= n && a[id[l]] == a[id[r + 1]]) ++r;
        ++sc;
        sl[sc] = l, sr[sc] = r;
    }
    int ans = 0;
    for (int i = 1; i <= sc; ) {
        ++ans;
        while (i + 1 <= sc && id[sr[i + 1]] < id[sl[i]]) ++i;
        ++i;
        while (i + 1 <= sc && id[sl[i + 1]] > id[sr[i]]) ++i;
        ++i;
    }
    printf("%d\n", ans);
}

int main() {
    work();
    return 0;
}