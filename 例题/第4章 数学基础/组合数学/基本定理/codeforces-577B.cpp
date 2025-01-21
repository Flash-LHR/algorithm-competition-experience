#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3 + 5;

int n, m, a[N], dp[N][N];

int main() {
    scanf("%d%d", &n, &m);
    if (n > m) {
		puts("YES");
		return 0;
	}
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] %= m;
        if (!a[i]) {
			puts("YES");
			return 0;
		}
        dp[i][a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] |= dp[i - 1][j];
            dp[i][(j + a[i]) % m] |= dp[i - 1][j];
        }
        if (dp[i][0]) {
			puts("YES");
			return 0;
		}
    }
    puts("NO");
    return 0;
}