for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        a[i][j] += a[i][j - 1]
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        a[i][j] += a[i-1][j]

for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= p; k++)
            a[i][j][k] += a[i - 1][j][k]
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= p; k++)
            a[i][j][k] += a[i][j - 1][k]
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= p; k++)
            a[i][j][k] += a[i][j][k - 1]