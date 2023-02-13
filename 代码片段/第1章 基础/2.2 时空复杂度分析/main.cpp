#include <iostream>
using namespace std;

int N;
long long sum = 0;
for (int i = 1; i <= N; i++) {
    sum += i;
}

int func(int n) {
    int cnt = 0;
    while (n) {
        if (n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}

int binary_Search(int l, int r, int v) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v == a[mid]) return mid;
        if (v > a[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void func(int n) {
    bool vis[maxn];
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            //...
        }
    }
}

for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j - 1) <= n; i++)
        d[i][j] = max(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
}

// O(n^3)
int d[N][N];
memset(d, 0x3f, sizeof d);
for (int i = 1; i <= n; i++) d[i][i] = 0;
for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        for (int k = i; k < j; k++) d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + w[i][j]);
    }
}

// O(2^n)
int Fibonacci(int n) {
    return n > 2 ? Fibonacci(n - 1) + Fibonacci(n - 2) : 1;
}

int main() {
    cout << "hello world" << endl;
    return 0;
}