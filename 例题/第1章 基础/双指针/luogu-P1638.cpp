// 解法一
#include <iostream>

using namespace std;
const int maxn = 1e6 + 10;

int a[maxn], cnt[2021];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int sum = 0, L, R, ans = 1e9;
    for (int l = 1, r = 1; l <= n; ++l) {
        while (r <= n && sum < m) {
            if (!cnt[a[r]]) ++sum;
            ++cnt[a[r++]];
        }
        if (sum == m && r - l < ans) {
            ans = r - l, L = l, R = r - 1;
        }
        if (--cnt[a[l]] == 0) --sum;
    }
    printf("%d %d\n", L, R);
    return 0;
}

// 解法二
#include <iostream>

using namespace std;
const int maxn = 1e6 + 10;

int a[maxn], cnt[2021];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int sum = 0, L, R, ans = 1e9;
    for (int l = 1, r = 1; r <= n; ++r) {
        if (++cnt[a[r]] == 1) ++sum;
        while (sum >= m) {
            if (r - l + 1 < ans) {
                ans = r - l + 1, L = l, R = r;
            }
            if (--cnt[a[l++]] == 0) --sum;
        }
    }
    printf("%d %d\n", L, R);
    return 0;
}
