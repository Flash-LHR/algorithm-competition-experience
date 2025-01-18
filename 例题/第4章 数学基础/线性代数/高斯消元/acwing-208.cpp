#include <bits/stdc++.h>

using namespace std;

bitset<35> A[35];

int Gauss(int n, int m) {
    int r = 1;
    for (int c = 1; c <= n; c++) {
        int k = r;
        while (k <= m && !A[k][c]) k++;
        if (k > m) continue;
        if (k != r) swap(A[k], A[r]);
        for (int i = r + 1; i <= m; i++) {
			if (A[i][c]) A[i] ^= A[r];
		}
        r++;
    }
    int ans = 1;
    if (r < m + 1) {
		for (int i = r; i <= m; i++)
            if (A[i][0]) {
				return -1;
			} else {
				ans <<= 1;
			}
	}
    return ans;
}

signed main() {
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) A[i].reset(), A[i].set(i);
        for (int i = 1; i <= n; i++) {
            cin >> x;
            A[i][0] = x;
        }
        for (int i = 1; i <= n; i++) {
            cin >> x;
            A[i][0] = A[i][0] ^ x;
        }
        int x, y;
        while (cin >> x >> y && x && y) A[y].set(x);
        int ans = Gauss(n, n);
        if (ans == -1)
            cout << "Oh,it's impossible~!!" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}