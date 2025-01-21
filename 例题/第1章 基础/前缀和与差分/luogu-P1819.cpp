#include <bits/stdc++.h>

using namespace std;

int a[150][150], sum[150][150];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + a[i][j];
        }
    }

    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int res = 0, pre_min = 0;
            for (int k = 1; k <= n; k++) {
                res = res + sum[j][k] - sum[i][k];
                ans = max(ans, res - pre_min);
                pre_min = min(pre_min, res);
            }
        }
    }
    cout << ans << endl;
    return 0;
}