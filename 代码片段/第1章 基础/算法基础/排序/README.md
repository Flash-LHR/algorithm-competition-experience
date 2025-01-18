## 选择排序

```c++
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
```

## 冒泡排序

```c++
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
```

## 插入排序

```c++
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
```

## 快速排序

```c++
void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int pos = rand() % (r - l + 1) + l;
    swap(nums[r], nums[pos]);
    int i = l, j = r, pivot = nums[r];
    while (i != j) {
        while (nums[i] <= pivot && i < j) i++;
        while (nums[j] >= pivot && i < j) j--;
        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[r]);
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);
}
```

```c++
void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int pos = rand() % (r - l + 1) + l;
    swap(nums[r], nums[pos]);
    int i = l - 1, pivot = nums[r];
    for (int j = l; j < r; ++j) {
        if (nums[j] <= pivot) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    quick_sort(nums, l, i);
    quick_sort(nums, i + 1, r);
}
```

```c++
void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int pos = rand() % (r - l + 1) + l;
    swap(nums[l], nums[pos]);
    int i = l, k = l + 1, j = r;
    int pivot = nums[l];
    while (k <= j) {
        if (nums[k] < pivot) {
            swap(nums[k], nums[i]);
            i++;
            k++;
        } else if (nums[k] > pivot) {
            swap(nums[k], nums[j]);
            j--;
        } else {
            k++;
        }
    }
    quick_sort(nums, l, i - 1);
    quick_sort(nums, j + 1, r);
}
```

## 归并排序

```c++
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
```

```c++
vector<int> temp;
 
void merge_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }  
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    for (i = l; i <= r; i++) nums[i] = temp[i];
}
 
void sortArray(vector<int>& nums) {
    temp.resize(nums.size());
    merge_sort(nums, 0, nums.size() - 1);
}
```

## 堆排序

```c++
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
```

