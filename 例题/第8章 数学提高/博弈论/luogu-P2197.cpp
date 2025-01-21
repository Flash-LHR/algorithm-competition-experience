#include <iostream>
using namespace std;
const int maxn = 1e4 + 10;
 
int a[maxn];
 
int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ans ^= a[i];
        }
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
