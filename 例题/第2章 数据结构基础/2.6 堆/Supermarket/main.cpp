#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = (int)1e4;

struct heap {
    int a[M + 5], n;
    void clear() {n = 0;}
    int size() {return n;}
    void up(int p) { //  向上调整
        while (p > 1) {
            if (a[p] > a[p>>1]) { //  子节点大于父节点，不满足大根堆性质
                swap(a[p], a[p>>1]);
                p >>= 1;
            } else break;
        }
    }
    void down(int p) { //  向下调整
        int s = p << 1;
        while (s <= n) {
            if (s < n && a[s] < a[s + 1]) s++; //  左右子节点中取较大者
            if (a[s] > a[p]) { //  子节点大于父节点，不满足大根堆性质
                swap(a[s], a[p]);
                p = s, s <<= 1;
            } else break;
        }
    }
    void push(int v) {
        a[++n] = v;
        up(n);
    }
    int top() {
        return a[1];
    }
    void pop() {
        a[1] = a[n--];
        down(1);
    }
    void remove(int k) {
        a[k] = a[n--];
        up(k), down(k);
    }
};

int n;
heap h;
int p[M + 5], d[M + 5], id[M + 5];

bool cmp(int a, int b) {
    return d[a] < d[b];
}

void work() {
    for (int i = 1; i <= n; i++) scanf("%d %d", &p[i], &d[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1, u; i <= n; i++) {
        u = id[i];
        if (h.size() < d[u]) h.push(-p[u]);
        else if (p[u] > -h.top()) {
            h.pop();
            h.push(-p[u]);
        }
    }
    int ans = 0;
    while (h.size()) {
        ans += -h.top();
        h.pop();
    }
    printf("%d\n", ans);
}

int main() {
    while (~scanf("%d", &n)) work();
    return 0;
}