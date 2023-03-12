/*
// 线性基模板
struct LB {
    ll a[105];
    bool isZero;
    int maxlen;
    vector<ll> all;

    void init(int len) {
        maxlen = len, isZero = 0;
        memset(a, 0, sizeof a);
    }

    void build(int n, ll *b) {
        for (int i = 1; i <= n; i++) {
            if (!insert(b[i])) isZero = 1;
        }
        all.clear();
        for (int i = 0; i <= maxlen; i++) {
            if (a[i]) all.push_back(a[i]);
        }
    }

    ll queryMax() {
        ll ans = 0;
        for (int i = 0; i <= maxlen; i++) {
            ans ^= a[i];
        }
        return ans;
    }

    ll queryMin() {
        if (isZero) return 0;
        for (int i = 0; i <= maxlen; i++) {
            if (a[i]) return a[i];
        }
    }

    bool ask(ll x) {
        for (int i = maxlen; i >= 0; i--) {
            if (x & (1LL << i)) x ^= a[i];
        }
        return x == 0;
    }

    bool insert(ll x) {
        for (int i = maxlen; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;
            if (a[i])
                x ^= a[i];
            else {
                for (int j = 0; j < i; j++) {
                    if (x & (1LL << j)) x ^= a[j];
                }
                for (int j = i + 1; j <= maxlen; j++) {
                    if (a[j] & (1LL << i)) a[j] ^= x;
                }
                a[i] = x;
                return 1;
            }
        }
        return 0;
    }

    ll queryKth(ll k) {
        if (isZero) k--;
        int cnt = all.size();
        if (k >= (1LL << cnt)) return -1;
        ll ans = 0;
        for (int i = 0; i < all.size(); i++) {
            if (k & (1LL << i)) ans ^= all[i];
        }
        return ans;
    }

    ll max_Xor_X(ll x) {
    	for (int i = maxlen; i >= 0; i--) {
			if ((x ^ a[i]) > x) x ^= a[i];
		}
		return x;
	}
};
*/
