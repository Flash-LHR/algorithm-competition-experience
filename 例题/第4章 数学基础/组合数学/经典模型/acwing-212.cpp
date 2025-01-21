#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100010;
const int mod = 1e9 + 9;

int n;
int p[N];
bool st[N];
ll fact[N];

int qkp(ll a, int k) {
	ll ans = 1;
	while (k) {
		if (k & 1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(st, 0, sizeof st);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
		int cnt = 0;
		ll res = 1;
		for (int i = 1; i <= n; i++) {
			if (st[i]) continue;
			cnt++;
			int len = 1;
			st[i] = true;
			for (int j = p[i]; j != i; j = p[j]) {
				st[j] = true, len++;
			}
			res = res * (len == 1 ? 1 : qkp(len, len - 2)) % mod;
			res = res * qkp(fact[len - 1], mod - 2) % mod;
		}
		res = res * fact[n - cnt] % mod;
		printf("%lld\n", res);
	}
	return 0;
}