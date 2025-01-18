#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[610][610];

int cal(int n, ll p) {
   	ll ans = 1;
	int flag = 0;
    for (int i = 1, j, k, l; i <= n; i++) {
        k = i;
        for (j = i; j <= n; j++) if (a[j][i]) {
			k = j;
            break;
		}
        if (a[k][i] == 0) return 0;
        for (++j; j <= n; j++) {
			if (a[j][i] && a[j][i] < a[k][i]) k = j;
		}
        if (i != k) {
            swap(a[k], a[i]);
            flag ^= 1;
        }
        for (j = i + 1; j <= n; j++) {
            if (a[j][i] > a[i][i]) {
                swap(a[j], a[i]);
                flag ^= 1;
            }
            while (a[j][i]) {
				l = a[i][i] / a[j][i];
                for (k = i; k <= n; k++) {
					a[i][k] = (a[i][k] + 1LL *(p - l) * a[j][k]) % p;
				}
                swap(a[j], a[i]);
                flag ^= 1;
            }
        }
        ans = ans * a[i][i] % p;
    }
    if (flag) return (p - ans) % p;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, p;
	cin >> n >> p;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] %= p;
        }
	}
	cout << cal(n, p) << endl;
}