## 二分

```c++
int binary_search(int *a, int l, int r, int v) {  // 在数组a区间[l,r]二分查找元素v
    while (l <= r) {
        int mid = (l + r) >> 1;        // 取中间位置
        if (v == a[mid]) return mid;   // 查找成功，则返回所在位置
        if (v > a[mid])
            l = mid + 1;   // 从后半部分继续查找
        else
            r = mid - 1;   // 从前半部分继续查找
    }
    return -1;   // 元素不存在，返回-1
}
```

```c++
int l = 1, r = n;
while (l < r) {
    int mid = (l + r) >> 1;
    if (a[mid] >= x)
        r = mid;
    else
        l = mid + 1;
}
```

```c++
int l = 1, r = n;
while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (a[mid] <= x)
        l = mid;
    else
        r = mid - 1;
}
```

```c++
int get_next(int *a, int n, int x) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
 
int get_prev(int *a, int n, int x) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
```

```c++
const double eps = 1e-8;
 
while (l + eps < r) {
    double mid = (l + r) / 2;
    if (check(mid))
        l = mid;
    else
        r = mid;
}
```

```c++
for (int i = 0; i < 100; i++) {
    if (check(mid))
        l = mid;
    else
        r = mid;
}
```

