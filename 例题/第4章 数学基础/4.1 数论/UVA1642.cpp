#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

ll a[maxn];
ll mg[105], pos[105];

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    int t, n, cnt;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            ans = max(ans, a[i]);              // 特判一个数是否为最优解
            for (int j = 1; j <= cnt; j++) {   // 枚举之前的gcd
                mg[j] = gcd(mg[j], a[i]);
                if (mg[j] == mg[j - 1]) {   // 如果出现相同则整体左移
                    for (int k = j; k < cnt; k++) mg[k] = mg[k + 1], pos[k] = pos[k + 1];
                    cnt--, j--;
                } else
                    ans = max(ans, (i - pos[j] + 1) * mg[j]);   // 否则更新答案
            }
            mg[++cnt] = a[i], pos[cnt] = i;   // 将这个数插入
        }
        printf("%lld\n", ans);
    }
    return 0;
}
