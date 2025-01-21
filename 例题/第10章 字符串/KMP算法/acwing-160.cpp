#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 2e5 + 10;

char s[maxn], t[maxn];
int n, m, q;
int next[maxn], f[maxn];

void get_next() {
	next[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && t[j] != t[i]) j = next[j - 1];
		if (t[i] == t[j]) next[i] = ++j;
		else next[i] = 0;
	}
}

void kmp() {
	get_next();
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != t[j]) j = next[j - 1];
		if (s[i] == t[j]) ++j;
		++f[j];
		if (j == m) j = next[j - 1];
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	scanf("%s%s", s, t);
	kmp();
	for (int i = m; i >= 1; i--) f[next[i - 1]] += f[i];
	int x;
	while (q--) {
		scanf("%d", &x);
		printf("%d\n", f[x] - f[x + 1]);
	}
    return 0;
}