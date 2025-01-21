#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int n;
int a[maxn];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_set<int> s;
    int mask = 0;
    int ans = 0;
    for (int k = 31; k >= 0; k--) {
        mask |= 1 << k;
        int res = ans | (1 << k);
        for (int i = 0; i < n; i++) {
            if (s.count(res ^ (a[i] & mask))) {
                ans |= 1 << k;
                break;
            }
            s.insert(a[i] & mask);
        }
        s.clear();
    }
    cout << ans << endl;
    return 0;
}