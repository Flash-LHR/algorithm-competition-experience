#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    int t, n, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = 0, ans = 1e9, sum = 0;
        while (l < n) {
            while (r < n && sum < s) sum += a[r++];
            if (sum < s) break;
            ans = min(ans, r - l);
            sum -= a[l++];
        }
        printf("%d\n", (ans == 1e9 ? 0 : ans));
    }
    return 0;
}
