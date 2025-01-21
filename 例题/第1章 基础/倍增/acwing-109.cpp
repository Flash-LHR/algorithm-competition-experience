#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

int T, n, m;
int a[maxn], b[maxn], c[maxn];
ll val;

void merge(int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, k = 0;
    while (i <= r1 && j <= r2) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i <= r1) c[k++] = a[i++];
    while (j <= r2) c[k++] = b[j++];
}

bool check(int l1, int r1, int l2, int r2) {
    int len = r2 - l2 + 1;
    for (int i = l2; i <= r2; i++) b[i - l2] = a[i];
    sort(b, b + len);
    merge(l1, r1, 0, len - 1);
    int i = 0, j = r2 - l1, k = 0;
    ll ans = 0;
    while (i < j && k < m) {
        ans += 1LL * (c[j] - c[i]) * (c[j] - c[i]);
        i++, j--, k++;
    }
    return ans <= val;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%lld", &n, &m, &val);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int p = 1, j = i;
            while (p) {
                if (j + p <= n && check(i, j, j + 1, j + p)) {
                    j += p;
                    for (int k = i; k <= j; k++) a[k] = c[k - i];
                    p <<= 1;
                } else
                    p >>= 1;
            }
            i = j;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}