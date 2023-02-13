#include <algorithm>
#include <iostream>
using namespace std;

int binary_Search(int *a, int l, int r, int v) {   // 在区间[l,r]二分查找元素v
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

int getNext(int *a, int l, int r, int x) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return a[l];
}

int getPrev(int *a, int l, int r, int x) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return a[l];
}

// int idx1 = lower_bound(a, a + n, x) - a;   // 在范围[0, n)的数组a找到大于等于x的第一个下标
// int idx2 = upper_bound(a + 1, a + n + 1, x) - a;   // 在范围[1, n]的数组a找到大于x的第一个下标

// const double eps = 1e-8;

// // 写法一
// while (l + eps < r) {
//     double mid = (l + r) / 2;
//     if (check(mid))
//         l = mid;
//     else
//         r = mid;
// }

// // 写法二
// for (int i = 0; i < 100; i++) {
//     if (check(mid))
//         l = mid;
//     else
//         r = mid;
// }

int main() {
    int a[7] = {-1, 1, 14, 566, 3444, 122222, -1};

    return 0;
}