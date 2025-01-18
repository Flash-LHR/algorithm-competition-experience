// 思路一
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1005;

struct Rectangle {
	int x1, y1;
	int x2, y2;
} a[maxn];

int tx[maxn * 2], ty[maxn * 2];
int d[maxn * 2][maxn * 2];

void add(int x1, int y1, int x2, int y2, int t = 1) {
	d[x1][y1] += t;
    d[x2 + 1][y2 + 1] += t;
   	d[x2 + 1][y1] -= t;
    d[x1][y2 + 1] -= t;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].x1;
		tx[i] = a[i].x1, tx[n + i] = a[i].x2;
		ty[i] = a[i].y1, ty[n + i] = a[i].y2;
	}
	sort(tx + 1, tx + 1 + n * 2);
	sort(ty + 1, ty + 1 + n * 2);	
	int len1 = unique(tx + 1, tx + 1 + n * 2) - tx - 1;
	int len2 = unique(ty + 1, ty + 1 + n * 2) - ty - 1;
 	for (int i = 1; i <= n; i++) {
		int x1 = lower_bound(tx + 1, tx + 1 + len1, a[i].x1) - tx;
		int y1 = lower_bound(ty + 1, ty + 1 + len2, a[i].y1) - ty;
		int x2 = lower_bound(tx + 1, tx + 1 + len1, a[i].x2) - tx;
		int y2 = lower_bound(ty + 1, ty + 1 + len2, a[i].y2) - ty;
		add(x1, y1, x2 - 1, y2 - 1);
	}
	long long ans = 0;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			if (d[i][j] > 0) {
				ans += 1LL * (tx[i + 1] - tx[i]) * (ty[j + 1] - ty[j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}


// 思路二
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1005;

struct Rectangle {
	int x1, y1;	// 左上
	int x2, y2;	// 右下
};

long long GetSquare(int w, vector<pair<int, int>> &s) {
	long long h = 0;
	sort(s.begin(), s.end());
	int l = s[0].first, r = s[0].second;
	for (int i = 1; i < s.size(); i++) {
		if (s[i].first <= r) {
			r = max(r, s[i].second);
		} else {
			h += r - l;
			l = s[i].first, r = s[i].second;
		}
	}
	h += r - l;
	return h * w;
}

int main() {
	int n;
	cin >> n;
	vector<Rectangle> a(n);
	vector<int> h(n * 2);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		h[i] = a[i].x1, h[n + i] = a[i].x2;
	}
	sort(h.begin(), h.end());
	long long ans = 0;
	for (int i = 1; i < h.size(); i++) {
		if (h[i] == h[i - 1]) continue;
		vector<pair<int, int>> s;
		for (int j = 0; j < n; j++) {
			if (a[j].x1 < h[i] && h[i] <= a[j].x2) {
				s.push_back({a[j].y2, a[j].y1});
			}
		}
		ans += GetSquare(h[i] - h[i - 1], s);
	}
	cout << ans << endl;
	return 0;
}