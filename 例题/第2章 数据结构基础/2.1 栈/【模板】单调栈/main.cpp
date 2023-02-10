#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e6;

int n, a[M + 5];
int st[M + 5], tp;
int f[M + 5];

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--) {
        while (tp && a[i] >= a[st[tp]]) tp--;
        f[i] = st[tp];
        st[++tp] = i;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", f[i], " \n"[i == n]);
}

int main() {
    work();
    return 0;
}