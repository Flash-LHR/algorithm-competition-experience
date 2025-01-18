#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;

struct node {
    int l, r, id;

    bool operator<(const node &p) const { return r >= p.r; }
} a[maxn];

bool cmp(node &p, node &q) { return p.l == q.l ? p.r < q.r : p.l < q.l; }

priority_queue<node> q;

int ans[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int cnt = 0;
    q.push({a[1].l, a[1].r, ++cnt});
    ans[a[1].id] = cnt;
    for (int i = 2; i <= n; i++) {
        node cur = q.top();
        if (cur.r < a[i].l) {
            q.pop();
            cur.r = a[i].r;
            ans[a[i].id] = cur.id;
            q.push(cur);
        } else {
            q.push({a[i].l, a[i].r, ++cnt});
            ans[a[i].id] = cnt;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}