#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int M = (int)1e6;

ull st[M + 5], x;
int tp, n;  // tp记录栈顶位置

void work() {
    scanf("%d", &n); tp = 0;
    char op[10];
    for (int i = 1; i <= n; i++) {
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {  // push
            scanf("%llu", &x);
            st[++tp] = x;
        } else if (op[0] == 'p') {  // pop
            if (tp) tp--;
            else puts("Empty");
        } else if (op[0] == 'q') {  // query
            if (tp) printf("%llu\n", st[tp]);
            else puts("Anguei!");
        } else printf("%d\n", tp);  // size
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
        work();
    }
    return 0;
}