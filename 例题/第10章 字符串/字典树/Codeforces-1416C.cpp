#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 3e5 + 100;

vector<int> node[N * 35];
int trie[N * 35][2], cnt;
ll f[35][2];

int newnode() {
    cnt++;
    trie[cnt][0] = trie[cnt][1] = 0;
    node[cnt].clear();
    return cnt;
}

void insert(int x, int id) {
    int pos = 0;
    for (int i = 30; i >= 0; i--) {
        int to = (x >> i) & 1;
        if (!trie[pos][to]) trie[pos][to] = newnode();
        pos = trie[pos][to];
        node[pos].push_back(id);
    }
}

void dfs(int pos, int deep) {
    if (deep == -1) return;
    int lson = trie[pos][0], rson = trie[pos][1];
    ll res = 0, r = 0;
    int lsz = node[lson].size(), rsz = node[rson].size();
    for (int i = 0; i < lsz; i++) {
        while (r < rsz && node[lson][i] > node[rson][r]) r++;
        res += r;
    }
    f[deep][0] += res;
    f[deep][1] += 1LL * lsz * rsz - res;
    if (lson) dfs(lson, deep - 1);
    if (rson) dfs(rson, deep - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        insert(num, i);
    }
    dfs(0, 30);
    ll ans = 0, x = 0;
    for (int i = 0; i <= 30; i++) {
        if (f[i][0] <= f[i][1])
            ans += f[i][0];
        else {
            ans += f[i][1];
            x |= (1 << i);
        }
    }
    printf("%lld %lld\n", ans, x);
    return 0;
}