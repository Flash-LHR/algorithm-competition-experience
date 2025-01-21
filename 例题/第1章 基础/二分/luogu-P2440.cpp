#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;

int n, k;
int a[maxn];

bool check(int x) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] / x;
    }
    return ans >= k;
}

int main() {
	int l = 1, r = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r = max(r, a[i]);
	}
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (check(l))
        cout << l << endl;
    else
        cout << 0 << endl;
    return 0;
}