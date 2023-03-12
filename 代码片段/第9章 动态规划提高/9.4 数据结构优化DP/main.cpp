const int mod = int(1e9) + 7
memset(f, 0, sizeof f);
a[0] = -inf
f[0][0] = 1
for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; j++)
        for (int k = 0; k < j; k++)
            if (a[k] < a[j])
                f[i][j] = (f[i][j] + f[i - 1][k]) % mod
int ans = 0;
for (int i = 1; i <= n; i++) ans = (ans + f[m][i]) % mod;
