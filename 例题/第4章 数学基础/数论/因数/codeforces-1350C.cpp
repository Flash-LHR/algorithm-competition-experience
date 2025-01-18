// 方法一
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

ll nums[maxn], suf[maxn];

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	suf[n] = nums[n];
	for (int i = n - 1; i >= 1; i--) {
		suf[i] = gcd(suf[i + 1], nums[i]);
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (ans == 0) {
			ans = lcm(nums[i], suf[i + 1]);
		} else {
			ans = gcd(ans, lcm(nums[i], suf[i + 1]));
		}
	}
	cout << ans << endl;
    return 0;
}

// 方法二
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

unordered_map<int, int> fi, se;
unordered_set<int> st;
vector<int> prime;
int minp[maxn], cnt[maxn];

void euler() {
    for (int i = 1; i < maxn; i++) minp[i] = i;
    for (int i = 2; i < maxn; i++) {
        if (minp[i] == i) prime.push_back(i);
        for (int j = 0; j < prime.size() && 1LL * i * prime[j] < maxn; j++) {
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

void divide(int n) {
    map<int, int> mp;
    while (n > 1) {
        mp[minp[n]]++;
        n /= minp[n];
    }
    for (auto value : mp) {
        int p = value.first, k = value.second;
        cnt[p]++, st.insert(p);
        if (!fi.count(p)) {
            fi[p] = k;
            continue;
        }
        if (!se.count(p)) {
            if (k < fi[p]) {
                se[p] = fi[p];
                fi[p] = k;
            } else
                se[p] = k;
            continue;
        }
        if (k <= fi[p]) {
            se[p] = fi[p];
            fi[p] = k;
        } else if (k < se[p]) {
            se[p] = k;
        }
    }
}

ll qkp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int n;
    cin >> n;
    euler();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        divide(x);
    }
    ll ans = 1;
    for (auto p : st) {
        if (cnt[p] >= n - 1) {
            if (cnt[p] == n - 1)
                ans *= qkp(p, fi[p]);
            else
                ans *= qkp(p, se[p]);
        }
    }
    cout << ans << endl;
    return 0;
}