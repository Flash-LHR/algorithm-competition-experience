#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

const int M = int(1e5);

int n, m;
bool f[M + 5];
int cnt[M + 5];
int a[M + 5], c[M + 5];

void work() {
    memset(f, 0, sizeof(bool) * (m + 1));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    f[0] = true;
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(int) * (m + 1));
        for (int j = a[i]; j <= m; j++)
            if (!f[j] && f[j - a[i]] && cnt[j - a[i]] < c[i])
                f[j] = true, cnt[j] = cnt[j - a[i]] + 1;
    }
    printf("%d\n", accumulate(f + 1, f + m + 1, 0));
}

int main() {
    while (~scanf("%d %d", &n, &m) && n + m) work();
    return 0;
}