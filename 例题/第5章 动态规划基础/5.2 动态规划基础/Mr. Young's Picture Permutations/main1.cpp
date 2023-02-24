#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

typedef long long ll;

int k, a[6];

void work() {
    memset(a, 0, sizeof a);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    int n = accumulate(a + 1, a + k + 1, 0);
    vector<vector<vector<vector<vector<ll>>>>> f = 
        vector<vector<vector<vector<vector<ll>>>>>(a[1] + 1, 
        vector<vector<vector<vector<ll>>>>(a[2] + 1, 
        vector<vector<vector<ll>>>(a[3] + 1, 
        vector<vector<ll>>(a[4] + 1, 
        vector<ll>(a[5] + 1, 0)))));
    f[0][0][0][0][0] = 1;
    for (int r1 = 0; r1 <= a[1]; r1++)
    for (int r2 = 0; r2 <= min(r1, a[2]); r2++)
    for (int r3 = 0; r3 <= min(r2, a[3]); r3++)
    for (int r4 = 0; r4 <= min(r3, a[4]); r4++)
    for (int r5 = 0; r5 <= min(r4, a[5]); r5++) if (r1 || r2 || r3 || r4 || r5) {
        if (r1) f[r1][r2][r3][r4][r5] += f[r1 - 1][r2][r3][r4][r5];
        if (r2) f[r1][r2][r3][r4][r5] += f[r1][r2 - 1][r3][r4][r5];
        if (r3) f[r1][r2][r3][r4][r5] += f[r1][r2][r3 - 1][r4][r5];
        if (r4) f[r1][r2][r3][r4][r5] += f[r1][r2][r3][r4 - 1][r5];
        if (r5) f[r1][r2][r3][r4][r5] += f[r1][r2][r3][r4][r5 - 1];
    }
    printf("%lld\n", f[a[1]][a[2]][a[3]][a[4]][a[5]]);
}

int main() {
    while (~scanf("%d", &k) && k) work();
    return 0;
}