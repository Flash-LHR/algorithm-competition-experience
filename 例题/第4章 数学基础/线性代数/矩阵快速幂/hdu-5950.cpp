#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll Mod = 2147493647;
const int maxn = 2e5 + 10;
 
const int arr1[10][10] = {{1, 2, 1, 4, 6, 4, 1},
                          {1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 4, 6, 4, 1},
                          {0, 0, 0, 1, 3, 3, 1},
                          {0, 0, 0, 0, 1, 2, 1},
                          {0, 0, 0, 0, 0, 1, 1},
                          {0, 0, 0, 0, 0, 0, 1}};

int arr2[] = {0, 0, (1 << 4), (1 << 3), (1 << 2), (1 << 1), 1};
 
struct Matrix {
    ll matrix[10][10];
    int n, m;
 
    Matrix() {}
 
    Matrix(int x, int y) {
        n = x, m = y;
        memset(matrix, 0, sizeof(matrix));
    }
};
 
Matrix mul(Matrix a, Matrix b) {
    Matrix ans(a.n, b.m);
    for (int i = 1; i <= ans.n; i++) {
        for (int j = 1; j <= ans.m; j++) {
            for (int k = 1; k <= a.m; k++) {
                ans.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j] % Mod;
                ans.matrix[i][j] %= Mod;
            }
        }
    }
    return ans;
}
 
Matrix qkp(Matrix mx, ll n) {
    Matrix ans(mx.n, mx.m);
    for (int i = 1; i <= mx.n; i++) ans.matrix[i][i] = 1;
    while (n) {
        if (n & 1) ans = mul(ans, mx);
        mx = mul(mx, mx);
        n >>= 1;
    }
    return ans;
}
 
ll solve(ll n) {
    if (n == 1) return arr2[1];
    if (n == 2) return arr2[0];
    Matrix mx(7, 7);
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            mx.matrix[i][j] = arr1[i - 1][j - 1];
        }
    }
    Matrix dw(7, 1);
    for (int i = 1; i <= 7; i++) {
        dw.matrix[i][1] = arr2[i - 1];
    }
    Matrix ans = mul(qkp(mx, n - 2), dw);
    return ans.matrix[1][1];
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, T;
    cin >> T;
    while (T--) {
        cin >> n >> arr2[1] >> arr2[0];
        cout << solve(n) << endl;
    }
    return 0;
}
