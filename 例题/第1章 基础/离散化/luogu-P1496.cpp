#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e4 + 10;

pair<int, int> a[maxn];
int t[maxn * 2];
int h[maxn * 2];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
		t[i] = a[i].first;
		t[i + n] = a[i].second;
	}
	sort(t + 1, t + 1 + 2 * n);
	for (auto &pr : a) {
		int l = lower_bound(t + 1, t + 1 + 2 * n, pr.first) - t;
		int r = lower_bound(t + 1, t + 1 + 2 * n, pr.second) - t;
		++h[l];
		--h[r];
	}
	for (int i = 1; i <= 2 * n; i++) {
		h[i] += h[i - 1];
	}
	long long ans = 0;
	for (int i = 1; i < 2 * n; i++) {
		if (h[i] > 0) {
			ans += t[i + 1] - t[i];
		}
	}
	cout << ans << endl;
	return 0;
}