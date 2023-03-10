#include <bits/stdc++.h>
using namespace std;

const int M = int(1e3);
const int inf = 0x3f3f3f3f;

int a, b, n;
int s[M + 5][M + 5];
int t[M + 5][M + 5];
int q[M + 5];
int mx[M + 5][M + 5];
int mi[M + 5][M + 5];

void getRes(int res[][M + 5], function<bool(int, int)> cmp) {
    for (int i = 1; i <= a; i++) {
        int l = 1, r = 0;
        for (int j = 1; j <= b; j++) {
            while (l <= r && j - q[l] + 1 > n) l++;
            while (l <= r && !cmp(s[i][q[r]], s[i][j])) r--;
            q[++r] = j;
            t[i][j] = s[i][q[l]];
        }
    }

    for (int j = 1; j <= b; j++) {
        int l = 1, r = 0;
        for (int i = 1; i <= a; i++) {
            while (l <= r && i - q[l] + 1 > n) l++;
            while (l <= r && !cmp(t[q[r]][j], t[i][j])) r--;
            q[++r] = i;
            res[i][j] = t[q[l]][j];
        }
    }
}

void work() {
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) scanf("%d", &s[i][j]);
    getRes(mx, [](int a, int b) {return a > b;});
    getRes(mi, [](int a, int b) {return a < b;});
    int ans = inf;
    for (int i = n; i <= a; i++) for (int j = n; j <= b; j++) ans = min(ans, mx[i][j] - mi[i][j]);
    printf("%d\n", ans);
}

int main() {
    work();
    return 0;
}