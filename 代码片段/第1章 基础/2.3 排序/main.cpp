#include <iostream>
#include <queue>
using namespace std;

// 对n个数，区间范围[1,n]的数组a进行选择排序
void selection_sort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int k = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[i], a[k]);   // 交换数组中的两个元素
    }
}

// 对n个数，区间范围[1,n]的数组a进行冒泡排序
void bubble_sort(int* a, int n) {
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                ok = true;
                swap(a[i], a[i + 1]);
            }
        }
    }
}

// 对n个数，区间范围[1,n]的数组a进行插入排序
void insertion_sort(int* a, int n) {
    // [1, i]视为已排序的部分；[i + 1, n]视为未排序部分
    for (int i = 1; i <= n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j > 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// 对n个数，区间范围[1,n]的数组a进行快速排序
void quick_sort(int* a, int x, int y) {
    if (x >= y) return;
    int i = x, j = y, k = a[x];
    while (i != j) {
        while (a[j] >= k && i < j) j--;
        while (a[i] <= k && i < j) i++;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[i], a[x]);
    quick_sort(a, x, i - 1);
    quick_sort(a, i + 1, y);
}

int quick_search(int* a, int x, int y, int m) {
    if (x == y) return a[x];
    int i = x, j = y, k = a[x];
    while (i != j) {
        while (a[j] >= k && i < j) j--;
        while (a[i] <= k && i < j) i++;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[i], a[x]);
    if (i == m) return a[i];
    if (i < m)
        return quick_search(a, i + 1, y, m);
    else
        return quick_search(a, x, i - 1, m);
}

void merge(int* a, int* b, int* c, int n, int m) {
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

// 对区间范围[x,y)的数组a进行归并排序
void merge_sort(int* a, int* t, int x, int y) {
    if (y - x > 1) {
        int mid = x + (y - x) / 2;
        int p = x, q = mid, i = x;
        merge_sort(a, t, x, mid);
        merge_sort(a, t, mid, y);
        while (p < mid || q < y) {
            if (q >= y || (p < mid && a[p] <= a[q]))
                t[i++] = a[p++];
            else
                t[i++] = a[q++];
        }
        /*上面实际是这一部分的简写
        while (p < mid && q < y) {
            if (a[p] <= a[q])
                t[i++] = a[p++];
            else
                t[i++] = a[q++];
        }
        while (p < mid) t[i++] = a[p++];
        while (q < y) t[i++] = a[q++];
        */
        for (int i = x; i < y; i++) a[i] = t[i];   // 从辅助数组复制到原数组
    }
}

// const int N = 100010;

// int n, w, a[N];
// vector<int> bucket[N];

// void insertion_sort(vector<int>& A) {
//     for (int i = 1; i < A.size(); ++i) {
//         int key = A[i];
//         int j = i - 1;
//         while (j >= 0 && A[j] > key) {
//             A[j + 1] = A[j];
//             --j;
//         }
//         A[j + 1] = key;
//     }
// }

// void bucket_sort() {
//     int bucket_size = w / n + 1;
//     for (int i = 0; i < n; ++i) {
//         bucket[i].clear();
//     }
//     for (int i = 1; i <= n; ++i) {
//         bucket[a[i] / bucket_size].push_back(a[i]);
//     }
//     int p = 0;
//     for (int i = 0; i < n; ++i) {
//         insertion_sort(bucket[i]);
//         for (int j = 0; j < bucket[i].size(); ++j) {
//             a[++p] = bucket[i][j];
//         }
//     }
// }

// const int N = 100010;
// const int W = 100010;
// const int K = 100;

// int n, w[K], k, cnt[W];

// struct Element {
//     int key[K];

//     bool operator<(const Element& y) const {
//         // 两个元素的比较流程
//         for (int i = 1; i <= k; ++i) {
//             if (key[i] == y.key[i]) continue;
//             return key[i] < y.key[i];
//         }
//         return false;
//     }
// } a[N], b[N];

// void counting_sort(int p) {
//     memset(cnt, 0, sizeof(cnt));
//     for (int i = 1; i <= n; ++i) ++cnt[a[i].key[p]];
//     for (int i = 1; i <= w[p]; ++i) cnt[i] += cnt[i - 1];
//     // 为保证排序的稳定性，此处循环i应从n到1
//     // 即当两元素关键字的值相同时，原先排在后面的元素在排序后仍应排在后面
//     for (int i = n; i >= 1; --i) b[cnt[a[i].key[p]]--] = a[i];
//     memcpy(a, b, sizeof(a));
// }

// void radix_sort() {
//     for (int i = k; i >= 1; --i) {
//         // 借助计数排序完成对关键字的排序
//         counting_sort(i);
//     }
// }

// // 对长度为n，区间范围[0,n)的数组a进行基数排序
// void radix_sort(int n, int* a) {
//     int* b = new int[n];   // 临时空间
//     int* cnt = new int[1 << 8];
//     int mask = (1 << 8) - 1;
//     int *x = a, *y = b;
//     for (int i = 0; i < 32; i += 8) {
//         for (int j = 0; j != (1 << 8); ++j) cnt[j] = 0;
//         for (int j = 0; j != n; ++j) ++cnt[x[j] >> i & mask];
//         for (int sum = 0, j = 0; j != (1 << 8); ++j) {
//             // 等价于 std::exclusive_scan(cnt, cnt + (1 << 8), cnt, 0);
//             sum += cnt[j], cnt[j] = sum - cnt[j];
//         }
//         for (int j = 0; j != n; ++j) y[cnt[x[j] >> i & mask]++] = x[j];
//         std::swap(x, y);
//     }
//     delete[] cnt;
//     delete[] b;
// }

// 对长度为n，区间范围[1,n]的数组a进行基数排序
void heap_sort(int* a, int n) {
    // 创建小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) q.push(a[i]);
    for (int i = 1; i <= n; i++) {
        if (!q.empty()) {
            a[i] = q.top();
            q.pop();
        }
    }
}

// 对长度为n，区间范围[0,n)的数组a进行希尔排序
void shell_sort(int* a, int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                swap(a[j], a[j - h]);
            }
        }
        h = h / 3;
    }
}

int main() {
    int a[] = {12, 32, 42, 23, 2, 3, 59111, 2333};
    // selection_sort(a, 8);
    // bubble_sort(a, 8);
    // insertion_sort(a, 8);
    // quick_sort(a, 1, 8);
    // cout << quick_search(a, 1, 8, 8) << endl;
    // int t[10];
    // merge_sort(a, t, 1, 8);
    // heap_sort(a, 8);
    shell_sort(a, 8);
    for (int i = 0; i < 8; i++) cout << a[i] << " ";

    return 0;
}