```c++
int findClosest(int arr[], int n, int target) {
    int i = 0, p = 1;
    while (p) {
        if (i + p < n && arr[i + p] <= target) {
            i += p;
            p <<= 1;
        } else {
            p >>= 1;
        }
    }
    return i;
}
```

