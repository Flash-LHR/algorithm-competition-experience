#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

struct ACAM {
    int cnt;
    int fail[M + 5];
    int ending[M + 5];
    int nx[M + 5][26];
    bool vis[M + 5];
    vector<int> g[M + 5];

    ACAM()
    {
        vis[0] = false;
        cnt = fail[0] = ending[0] = 0;
        memset(nx[0], 0, sizeof nx[0]);
    }

    int newnode()
    {
        ++cnt;
        vis[cnt] = false;
        fail[cnt] = ending[cnt] = 0;
        memset(nx[cnt], 0, sizeof nx[cnt]);
        return cnt;
    }

    void insert(char *s)
    {
        int u = 0;
        for (int i = 1, v; s[i]; ++i) {
            v = s[i] - 'a';
            if (nx[u][v] == 0) nx[u][v] = newnode();
            u = nx[u][v];
        }
        ++ending[u];
    }

    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (nx[0][i]) {
                fail[nx[0][i]] = 0;
                q.push(nx[0][i]);
            }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0, v; i < 26; ++i)
                if (nx[u][i]) {
                    v = nx[u][i];
                    fail[v] = fail[u];
                    while (fail[v] && nx[fail[v]][i] == 0) fail[v] = fail[fail[v]];
                    if (nx[fail[v]][i]) fail[v] = nx[fail[v]][i];
                    q.push(v);
                }
        }
        for (int i = 1; i <= cnt; ++i) g[fail[i]].push_back(i);
    }

    void dfs(int u)
    {
        for (const int &v : g[u]) {
            dfs(v);
            vis[u] |= vis[v];
        }
    }

    int query(char *s)
    {
        for (int i = 1, u = 0, v; s[i]; ++i) {
            v = s[i] - 'a';
            while (u && nx[u][v] == 0) u = fail[u];
            if (nx[u][v]) u = nx[u][v];
            vis[u] = 1;
        }
        dfs(0);
        int ans = 0;
        for (int i = 1; i <= cnt; ++i)
            if (vis[i]) ans += ending[i];
        return ans;
    }
} acam;

char s[M + 5];

void work()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        acam.insert(s);
    }
    acam.build();
    scanf("%s", s + 1);
    printf("%d\n", acam.query(s));
}

int main()
{
    work();
    return 0;
}
