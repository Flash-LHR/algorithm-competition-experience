#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int M = (int)1e6;
const int inf = 0x3f3f3f3f;

int q, mx[M + 5];
int pre[M + 5], preTp;
int suf[M + 5], sufTp;

void work() {
    mx[0] = -inf;
    preTp = sufTp = 0;
    for (int i = 1, op, x, k, s = 0; i <= q; i++) {
        getchar(); op = getchar();
        if (op == 'I') {
            scanf("%d", &x);
            pre[++preTp] = x;
            s += x;
            mx[preTp] = max(mx[preTp - 1], s);
        } else if (op == 'D') {
            if (preTp) s -= pre[preTp--];
        } else if (op == 'L') {
            if (preTp) {
                suf[++sufTp] = pre[preTp];
                s -= pre[preTp--];
            }
        } else if (op == 'R') {
            if (sufTp) {
                pre[++preTp] = suf[sufTp];
                s += suf[sufTp--];
                mx[preTp] = max(mx[preTp - 1], s);
            }
        } else {
            scanf("%d", &k);
            printf("%d\n", mx[k]);
        }
    }
}

int main() {
    while (~scanf("%d", &q)) work();
    return 0;
}