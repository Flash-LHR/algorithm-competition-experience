#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int Mod = 99991;

int w[maxn][6], head[maxn], nxt[maxn];
int tmp1[12], tmp2[12];

int Hash(int *t) {
	int x = 0, y = 1;
	for (int j = 0; j < 6; j++) {
		x = (x + t[j]) % Mod;
		y = 1LL * y * t[j] % Mod;
	}
	return (x + y) % Mod;
}

bool cmp(int *a, int st1, int *b, int st2) {
	for (int i = 0; i < 6; i++) {
		if (a[st1 + i] != b[st2 + i]) return false;
	}
	return true;
}

bool Check(int *a, int *b) {
	const int N = 6;
    for (int i = 0; i < N; i++) {
		tmp1[i] = tmp1[i + N] = a[i];
		tmp2[i] = tmp2[i + N] = b[i];
	}
	int l = 0, r = 1, k;
	while (l < N && r < N) {
		for (k = 0; k < N && tmp1[l + k] == tmp1[r + k]; k++);
		if (k == N) break;
		if (tmp1[l + k] > tmp1[r + k]) {
			l += k + 1;
			if (l == r) ++l;
		} else {
			r += k + 1;
			if (l == r) ++r;
		}
	}
	int st1 = min(l, r);
	l = 0, r = 1;
	while (l < N && r < N) {
		for (k = 0; k < N && tmp2[l + k] == tmp2[r + k]; k++);
		if (k == N) break;
		if (tmp2[l + k] > tmp2[r + k]) {
			l += k + 1;
			if (l == r) ++l;
		} else {
			r += k + 1;
			if (l == r) ++r;
		}
	}
	int st2 = min(l, r);
	return cmp(tmp1, st1, tmp2, st2);
}

bool Equal(int *a, int k) {
	int idx = Hash(a);
	int c[6];
	for (int i = 0; i < 6; i++) c[i] = a[5 - i];
	for (int i = head[idx]; i; i = nxt[i]) {
		if (Check(a, w[i]) || Check(c, w[i])) {
			return true;
		}
	}
	nxt[k] = head[idx];
	head[idx] = k;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> w[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (Equal(w[i], i)) {
			cout << "Twin snowflakes found." << endl;
			return 0;
		}
	}
	cout << "No two snowflakes are alike." << endl;
    return 0;
}