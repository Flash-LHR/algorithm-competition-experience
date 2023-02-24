#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
inline bool cmax(T &a, const T &b) {return a < b ? a = b, true : false;}

const int M = int(2e2);
const int N = 20;
const int O = N * N;
const int inf = 0x3f3f3f3f;

int n, m, ca;
int p[M + 5], d[M + 5];
int f[M + 5][N + 5][O * 2 + 5];

void work() {
    for (int i = 1; i <= n; i++) scanf("%d %d", &p[i], &d[i]);
    memset(f, -inf, sizeof f);
    f[0][0][O] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, m); j++) {
            for (int k = 0; k <= O * 2; k++) {
                f[i][j][k] = f[i - 1][j][k];
                if (j > 0 && k - p[i] + d[i] >= 0 && k - p[i] + d[i] <= 2 * O)
                    cmax(f[i][j][k], f[i - 1][j - 1][k - p[i] + d[i]] + p[i] + d[i]);
            }
        }
    }
    int mx = -inf, diff = -1;
    for (int i = 0; mx < 0; i++) {
        if (cmax(mx, f[n][m][O - i])) diff = O - i;
        if (cmax(mx, f[n][m][O + i])) diff = O + i;
    }
    vector<int> v;
    int sp = 0, sd = 0;
    int i = n, j = m, k = diff;
    while (j) {
        if (f[i][j][k] != f[i - 1][j][k])
            j--,
            k -= p[i] - d[i],
            sp += p[i],
            sd += d[i],
            v.push_back(i);
        --i;
    }
    printf("Jury #%d\n", ++ca);
    printf("Best jury has value %d for prosecution and value %d for defence:\n", sp, sd);
    for (int i = int(v.size()) - 1; i >= 0; i--) printf(" %d", v[i]);
    printf("\n\n");
}

int main() {
    while (~scanf("%d %d", &n, &m) && n + m) work();
    return 0;
}