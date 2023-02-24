/**
状态表示 dp[i][j][k]: 在 1 ~ i 个人中，选了 j 个人，D - P 值为 k，时的 D +P 最大值
状态计算 dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][k - (d[i] - p[i])] + d[i] + p[i])
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = (int)2e2;
const int N = (int)20;
const int K = (int)8e2;
const int inf = 0x3f3f3f3f;

int p[M + 5], d[M + 5];
int dp[M + 5][N + 5][K + 5];
int st[N + 5];

int main()
{
    int n, m, ca = 0;
    while(~scanf("%d %d", &n, &m) && (n + m))
    {
        for(int i = 1; i <= n; ++i) scanf("%d %d", &p[i], &d[i]);
        memset(dp, -inf, sizeof(dp)), dp[0][0][400] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= min(i, m); ++j)
            {
                for(int k = 0; k <= 800; ++k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(k - (d[i] - p[i]) < 0 || k - (d[i] - p[i]) > 800)    continue;
                    if(j)   dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - (d[i] - p[i])] + d[i] + p[i]);
                }
            }
        }
        int v = 0;
        while(dp[n][m][400 - v] < 0 && dp[n][m][400 + v] < 0)   v++;
        if(dp[n][m][400 - v] > dp[n][m][400 + v])               v = 400 - v;
        else                                                    v = 400 + v;
        int _d = (dp[n][m][v] + v - 400) / 2, _p = (dp[n][m][v] - v + 400) / 2;
        printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n", ++ca, _p, _d);
        int i = n, j = m, k = v, tp = 0;
        while(j)
        {
            if(dp[i][j][k] == dp[i - 1][j][k])  --i;
            else                                st[++tp] = i, k -= d[i] - p[i], --i, --j;
        }
        while(tp)   printf(" %d", st[tp--]);
        printf("\n\n");
    }
    return 0;
}