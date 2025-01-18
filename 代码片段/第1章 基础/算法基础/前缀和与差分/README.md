## 前缀和

```c++
for(int i = 1; i <= n; i++) {
    S[i] = S[i - 1] + a[i];
}
```

```c++
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
    }
}
```

## 差分

```c++
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
    }
}
```

```c++
void addVal(int x1, int y1, int x2, int y2, int t) {
    if(x1 > x2 || y1 > y2) {
        addVal(x2, y2, x1, y1);
        return;
    }
    d[x1][y1] += t;
    d[x2 + 1][y2 + 1] += t;
    d[x2 + 1][y1] -= t;
    d[x1][y2 + 1] -= t;
}
```

