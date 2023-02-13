#include <iostream>

using namespace std;
const int maxn = 1e6 + 10;

int a[maxn], cnt[2021];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = 0;
    int sum = 0, L, R, ans = 1e9;
    while (l <= n) {
        while (r < n && sum < m) {
            if (!cnt[a[r + 1]]) sum++;
            cnt[a[++r]]++;
        }
        if (sum == m && r - l + 1 < ans) {
            ans = r - l + 1;
            L = l, R = r;
        }
        if (--cnt[a[l++]] == 0) sum--;
    }
    printf("%d %d\n", L, R);
    return 0;
}