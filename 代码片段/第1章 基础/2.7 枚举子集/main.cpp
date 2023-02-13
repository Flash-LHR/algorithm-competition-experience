#include <iostream>

using namespace std;
const int maxn = 1005;

// int a[maxn], ans[maxn];
// int n;

// void print_subset(int cur) {   // cur初始输入1
//     for (int i = 1; i < cur; i++) printf("%d%c", ans[i], i == cur - 1 ? '\n' : ' ');
//     int s = ans[cur - 1] + 1;   // 确定当前最小元素
//     for (int i = s; i <= n; i++) {
//         ans[cur] = i;
//         print_subset(cur + 1);
//     }
// }

bool vis[maxn];
int a[maxn];
int n;

void print_subset(int cur) {
    if (cur == n + 1) {
        for (int i = 1; i <= n; i++)
            if (vis[i]) printf("%d ", a[i]);
        printf("\n");
        return;
    }
    vis[cur] = 1;
    print_subset(cur + 1);
    vis[cur] = 0;
    print_subset(cur + 1);
}

void print_set(int s) {
    for (int i = 0; i < n; i++)
        if (s & (1 << i)) printf("%d ", i);
    printf("\n");
}

void print_subset(int n) {
    for (int i = 0; i < (1 << n); i++) print_subset(i);
}

int main() {
    n = 5;
    for (int i = 1; i <= 5; i++) a[i] = i;
    print_subset(1);
    return 0;
}