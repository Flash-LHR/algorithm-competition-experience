#include <iostream>

using namespace std;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

static char buf[100000], *pa = buf, *pb = buf;
#define gc pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb) ? EOF : *pa++

inline int read() {
    register int x(0);
    register char c(gc);
    while (c < '0' || c > '9') c = gc;
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = gc;
    return x;
}

void write(int a) {
    if (a < 0) putchar('-'), a = -a;
    if (a >= 10) write(a / 10);
    putchar(a % 10 + 48);
}

int main() {
    return 0;
}