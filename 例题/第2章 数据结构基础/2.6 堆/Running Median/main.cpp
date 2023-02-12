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

heap left, right;

void work() {
    left.clear(), right.clear();
    int ca, n; scanf("%d %d", &ca, &n);
    printf("%d %d\n", ca, (n + 1) / 2);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if (left.size() == 0 || x > left.top()) right.push(-x);
        else left.push(x);
        while (right.size() > left.size() + 1) {
            left.push(-right.top());
            right.pop();
        }
        while (right.size() < left.size()) {
            right.push(-left.top());
            left.pop();
        }
        if (i % 20 == 0) printf("\n");
        if (i & 1) printf("%d ", -right.top());
    }
    printf("\n");
}

int main() {
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) work();
    return 0;
}