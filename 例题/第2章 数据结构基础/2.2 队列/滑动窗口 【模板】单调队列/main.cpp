#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

int n, k, a[M + 5];
int q[M + 5];

void work() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1, l = 1, r = 0; i <= n; i++) {
        while (l <= r && i - q[l] >= k) l++;
        while (l <= r && a[i] < a[q[r]]) r--;
        q[++r] = i;
        if (i >= k) printf("%d%c", a[q[l]], " \n"[i == n]);
    }
    for (int i = 1, l = 1, r = 0; i <= n; i++) {
        while (l <= r && i - q[l] >= k) l++;
        while (l <= r && a[i] > a[q[r]]) r--;
        q[++r] = i;
        if (i >= k) printf("%d%c", a[q[l]], " \n"[i == n]);
    }
}

int main() {
    work();
    return 0;
}