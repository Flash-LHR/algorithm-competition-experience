#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

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
} h;

void work() {
    int n; scanf("%d", &n);
    for (int i = 1, op, x; i <= n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            h.push(-x);
        } else if (op == 2) {
            printf("%d\n", -h.top());
        } else h.pop();
    }
}

int main() {
    work();
    return 0;
}