#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = (int)1e3;

int n, a[M + 5];
int f[M + 5];

int lis() {
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
    }
    return *max_element(f + 1, f + n + 1);
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d\n", lis());
}

int main() {
    work();
    return 0;
}