#include <iostream>

using namespace std;

int sum[105][105];

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
    }
}

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        // 前缀和：sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
}

void add(int i, int j, int x, int y, int val) {
    d[i][j] += val, d[x + 1][y + 1] += val;
    d[x + 1][j] -= val, d[i][y + 1] -= val;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[10][10];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    return 0;
}