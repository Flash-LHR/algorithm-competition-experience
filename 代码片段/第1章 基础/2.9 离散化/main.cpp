#include <algorithm>
#include <iostream>
using namespace std;

// int a[n];
// sort(a, a + n);
// int num = unique(a, a + n) - a;   // 输出离散化后数组的元素个数

int main() {
    int a[10] = {0, 1, 34, 2, 44, 22};
    sort(a + 1, a + 1 + 5);
    int len = unique(a + 1, a + 5 + 1) - a - 1;
    // cout << len << endl;
    int pos = lower_bound(a + 1, a + 1 + 5, 1) - a;
    cout << pos << endl;
    return 0;
}