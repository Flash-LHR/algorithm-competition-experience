// 解法一
#include <cstdio>

using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int a[maxn];

int main() {
    int t, n, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans = inf, sum = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n && sum < s) sum += a[r++];
            if (sum >= s) ans = r - l < ans ? r - l : ans;
            sum -= a[l];
        }
        printf("%d\n", (ans == inf ? 0 : ans));
    }
    return 0;
}

// 解法二
#include <cstdio>

using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int a[maxn];

int main() {
    int t, n, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans = inf, sum = 0;
        for (int l = 0, r = 0; r < n; r++) {
            sum += a[r];
            while (sum >= s) {
                ans = r - l + 1 < ans ? r - l + 1 : ans;
                sum -= a[l++];
            }
        }
        printf("%d\n", (ans == inf ? 0 : ans));
    }
    return 0;
}