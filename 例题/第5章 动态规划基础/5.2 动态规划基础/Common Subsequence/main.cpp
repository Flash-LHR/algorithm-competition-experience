#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = (int)1e3;

char s[M + 5], t[M + 5];
int f[M + 5][M + 5];

void work() {
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (s[i] == t[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    printf("%d\n", f[n][m]);
}

int main() {
    while (~scanf("%s %s", s + 1, t + 1)) work();
    return 0;
}