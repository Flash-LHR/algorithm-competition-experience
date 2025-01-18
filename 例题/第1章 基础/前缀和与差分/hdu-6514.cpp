#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int maxn = 1e7 + 10;

void add(vector<vector<int>> &d, int i, int j, int x, int y, int val) {
    d[i][j] += val, d[x + 1][y + 1] += val;
    d[i][y + 1] -= val, d[x + 1][j] -= val;
}

int getSum(vector<vector<int>> &d, int i, int j, int x, int y) {
    return d[x][y] - d[i - 1][y] - d[x][j - 1] + d[i - 1][j - 1];
}

int main() {
    int n, m, p, q;
    int lx, ly, rx, ry;
    while (scanf("%d%d", &n, &m) != EOF) {
        vector<vector<int>> d(n + 2, vector<int>(m + 2));
        scanf("%d", &p);
        while (p--) {
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            lx = n + 1 - lx, rx = n + 1 - rx;
            swap(lx, rx);
            add(d, lx, ly, rx, ry, 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (d[i][j]) d[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            }
        }
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            lx = n + 1 - lx, rx = n + 1 - rx;
            swap(lx, rx);
            int ans = getSum(d, lx, ly, rx, ry);
            if (ans == (rx - lx + 1) * (ry - ly + 1))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}