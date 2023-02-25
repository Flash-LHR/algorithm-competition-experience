#include <bits/stdc++.h>

using namespace std;
#define ENDL "\n"
typedef long long ll;
const int maxn = 2e4 + 10;
const int limit = 1e9;

ll c[maxn][50];
int len[maxn];

void init() {
    c[0][0] = c[1][0] = c[1][1] = 1;
    len[0] = 1, len[1] = 2;
    for (int i = 2, k; i < maxn; i++) {
        c[i][0] = 1, k = i + 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] > limit) {
                k = j;
                break;
            }
        }
        len[i] = k;
    }
}

ll cal(int n) {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < len[i]; j++) {
            if (c[i][j] == n) {
                return 1LL * i * (i + 1) / 2 + j + 1;
            }
        }
    }
    return 1LL * n * (n + 1) / 2 + 2;
}

int main() {
    init();
    int n;
    cin >> n;
    cout << cal(n) << endl;
    return 0;
}
