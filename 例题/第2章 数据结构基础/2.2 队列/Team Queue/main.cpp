#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = (int)1e3;
const int N = (int)1e6;

struct queue {
    int q[M + 5], l, r;
    void push(int x) {q[++r] = x;}
    void pop() {l++;}
    int front() {return q[l];}
    void clear() {l = 1, r = 0;}
    bool empty() {return l == r + 1;}
} cat, team[M + 5];

int t, tag[N + 5];

void work() {
    cat.clear();
    for (int i = 1, n, x; i <= t; i++) {
        team[i].clear();
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &x);
            tag[x] = i;
        }
    }
    char op[10]; int x;
    while (scanf("%s", op) && op[0] != 'S') {
        if (op[0] == 'E') {
            scanf("%d", &x);
            if (team[tag[x]].empty()) cat.push(tag[x]);
            team[tag[x]].push(x);
        } else {
            printf("%d\n", team[cat.front()].front());
            team[cat.front()].pop();
            if (team[cat.front()].empty()) cat.pop();
        }
    }
    printf("\n");
}

int main() {
    int ca = 0;
    while (scanf("%d", &t) && t) {
        printf("Scenario #%d\n", ++ca);
        work();
    }
    return 0;
}