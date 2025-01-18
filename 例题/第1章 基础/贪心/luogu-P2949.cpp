#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	long long sum = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (q.size() < a[i - 1].first) {
			sum += a[i - 1].second;
			q.push(a[i - 1].second);
		} else {
			if (a[i - 1].second > q.top()) {
				sum -= q.top();
				q.pop();
				sum += a[i - 1].second;
				q.push(a[i - 1].second);
			}
		}
	}
	cout << sum << endl;
	return 0;
}
