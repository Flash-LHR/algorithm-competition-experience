#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline bool cmin(T &a, const T &b) {return a > b ? a = b, true : false;}

typedef double db;

const db eps = 1e-6;
const int inf = 0x3f3f3f3f;

inline int sign(db a) {return a < -eps ? -1 : a > eps;}
inline int cmp(db a, db b) {return sign(a - b);}

int A, B, C, D; 
db f[20][20][20][20][5][5];

db dfs(int a, int b, int c, int d, int x, int y) {
    if (cmp(f[a][b][c][d][x][y], -1.) != 0) return f[a][b][c][d][x][y];
    f[a][b][c][d][x][y] = 0.;
    int s = a + b + c + d + (x != 4) + (y != 4);
    if (a < 13) f[a][b][c][d][x][y] += (13. - a) / (54. - s) * dfs(a + 1, b, c, d, x, y);
    if (b < 13) f[a][b][c][d][x][y] += (13. - b) / (54. - s) * dfs(a, b + 1, c, d, x, y);
    if (c < 13) f[a][b][c][d][x][y] += (13. - c) / (54. - s) * dfs(a, b, c + 1, d, x, y);
    if (d < 13) f[a][b][c][d][x][y] += (13. - d) / (54. - s) * dfs(a, b, c, d + 1, x, y);
    if (x == 4) {
        db mi = inf;
        cmin(mi, dfs(a, b, c, d, 0, y));
        cmin(mi, dfs(a, b, c, d, 1, y));
        cmin(mi, dfs(a, b, c, d, 2, y));
        cmin(mi, dfs(a, b, c, d, 3, y));
        f[a][b][c][d][x][y] += 1. / (54. - s) * mi;
    }
    if (y == 4) {
        db mi = inf;
        cmin(mi, dfs(a, b, c, d, x, 0));
        cmin(mi, dfs(a, b, c, d, x, 1));
        cmin(mi, dfs(a, b, c, d, x, 2));
        cmin(mi, dfs(a, b, c, d, x, 3));
        f[a][b][c][d][x][y] += 1. / (54. - s) * mi;
    }
    return f[a][b][c][d][x][y] += 1.;
}

void work() {
    scanf("%d %d %d %d", &A, &B, &C, &D);
    vector<int> v{A, B, C, D};
    if (accumulate(v.begin(), v.end(), 0, 
        [](int x, int y) {return x + max(0, y - 13);}) > 2)
        return puts("-1.000"), void();
    for (int i = 0; i <= 13; i++)
    for (int j = 0; j <= 13; j++)
    for (int k = 0; k <= 13; k++)
    for (int l = 0; l <= 13; l++)
    for (int x = 0; x < 5; x++)
    for (int y = 0; y < 5; y++) {
        int a = i + (x == 0) + (y == 0);
        int b = j + (x == 1) + (y == 1);
        int c = k + (x == 2) + (y == 2);
        int d = l + (x == 3) + (y == 3);
        if (a >= A && b >= B && c >= C && d >= D)
            f[i][j][k][l][x][y] = .0;
        else f[i][j][k][l][x][y] = -1.;
    }
    db ans = dfs(0, 0, 0, 0, 4, 4);
    printf("%.3f\n", ans);
}

int main() {
    work();
    return 0;
}