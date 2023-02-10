#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

struct node {
    int x, nx;
} node[M + 5];

void work() {
    int m; scanf("%d", &m);
    int head = 0, tail = M + 1;
    node[head].nx = tail;
    char op[10];
    for (int i = 1, cnt = 0, x, k; i <= m; i++) {
        scanf("%s", op);
        if (op[0] == 'H') {
            scanf("%d", &x);
            ++cnt;
            node[cnt].x = x;
            node[cnt].nx = node[0].nx;
            node[0].nx = cnt;
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            node[k].nx = node[node[k].nx].nx;
        } else if (op[0] == 'I') {
            scanf("%d %d", &k, &x);
            ++cnt;
            node[cnt].x = x;
            node[cnt].nx = node[k].nx;
            node[k].nx = cnt;
        }
    }
    int cur = head;
    while (node[cur].nx != tail) printf("%d ", node[cur = node[cur].nx].x);
    printf("\n");
}

int main() {
    work();
    return 0;
}