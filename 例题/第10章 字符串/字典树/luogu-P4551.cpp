#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int maxm = 3e6 + 10;

struct node {
    int to, w;
};

int tot;
vector<node> G[maxn];
ll a[maxn];
int trie[maxm][2];

void dfs(int fa, int u) {
    for(auto v: G[u]) {
        if(v.to != fa) {
            a[v.to] = a[u] ^ v.w;
            dfs(u, v.to);
        }
    }
}

void ins(int x) {
    int cur = 0;
    for(int i = 30; ~i; i--) {
        int ch = (x >> i) & 1;
        if(!trie[cur][ch]) trie[cur][ch] = ++tot;
        cur = trie[cur][ch];
    }
}

ll cal(int x) {
    int cur = 0;
    ll ans = 0;
    for(int i = 30; ~i; i--) {
        int ch = (x >> i) & 1;
        if(trie[cur][ch ^ 1]) {
            cur = trie[cur][ch ^ 1];
            ans += 1LL << i;
        } else cur = trie[cur][ch];
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(-1, 1);
    for(int i = 1; i <= n; i++) ins(a[i]);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, cal(a[i]));
    }
    cout << ans << endl;
    return 0;
}