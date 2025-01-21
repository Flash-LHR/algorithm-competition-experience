#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;
const int N = (int)2e6;

struct Trie {
    int tot;
    int nx[M + 5][26], go[M + 5][26];
    int q[M + 5], fail[M + 5], pos[M + 5], f[M + 5];

    void clear()
    {
        tot = 0;
        memset(nx[tot], 0, sizeof nx[tot]);
    }

    int newnode()
    {
        ++tot;
        memset(nx[tot], 0, sizeof nx[tot]);
        return tot;
    }

    void insert(char *s, int id)
    {
        int u = 0;
        for (int i = 0, v; s[i]; ++i) {
            v = s[i] - 'a';
            if (nx[u][v] == 0) nx[u][v] = newnode();
            u = nx[u][v];
        }
        pos[id] = u;
    }

    void build()
    {
        int l = 1, r = 0;
        fail[0] = 0;
        for (int i = 0; i < 26; ++i)
            if (nx[0][i]) {
                fail[nx[0][i]] = 0;
                go[0][i] = nx[0][i];
                q[++r] = nx[0][i];
            } else
                go[0][i] = 0;
        while (l <= r) {
            int u = q[l++];
            for (int i = 0; i < 26; ++i)
                if (nx[u][i]) {
                    go[u][i] = nx[u][i];
                    fail[nx[u][i]] = go[fail[u]][i];
                    q[++r] = nx[u][i];
                } else
                    go[u][i] = go[fail[u]][i];
        }
    }

    void solve(char *s, int n)
    {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            u = go[u][s[i] - 'a'];
            ++f[u];
        }
        for (int i = tot; i >= 1; --i) f[fail[q[i]]] += f[q[i]];
        for (int i = 0; i < n; ++i) printf("%d\n", f[pos[i]]);
    }
} tr;

char s[N + 5];

void work()
{
    int n;
    scanf("%d", &n);
    tr.clear();
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        tr.insert(s, i);
    }
    tr.build();
    scanf("%s", s);
    tr.solve(s, n);
}

int main()
{
    work();
    return 0;
}
