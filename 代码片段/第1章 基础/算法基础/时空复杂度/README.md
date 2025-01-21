```c++
int N = 100000;
long long sum = 0;
for (int i = 1; i <= N; i++) {
    sum += i;
}
```

```c++
int count(int n) {
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
```

```c++
int N;
long long sum = 0;
for (int i = 1; i <= N; i++) {
    sum += i;
}
```

```c++
void func(int n) {
    bool vis[maxn];
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            //...
        }
    }
}
```

```c++
int Fibonacci(int n) {
    return n > 2 ? Fibonacci(n - 1) + Fibonacci(n - 2) : 1;
}
```

