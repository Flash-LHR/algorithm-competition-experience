#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 5005;

int n, m;

struct cow {
    int l, r;
} a[maxn];

struct node {
    int s, c;
} b[maxn];

bool cmp1(const cow &p, const cow &q) {
    return p.r == q.r ? p.l < q.l : p.r < q.r;
}

bool cmp2(const node &p, const node &q) {
    return p.s < q.s;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
    for (int i = 1; i <= m; i++) cin >> b[i].s >> b[i].c;
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + m, cmp2);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[j].s >= a[i].l && b[j].s <= a[i].r && b[j].c) {
                ans++;
                b[j].c--;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}