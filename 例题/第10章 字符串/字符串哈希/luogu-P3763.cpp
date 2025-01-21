#include <bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;

const int N = 1e5 + 5, base = 13331;
int ans, lens, lens0;
string s0, s;
ull pw[N], hs_s0[N], hs_s[N];

ull get_hs(ull hs[], int l, int r) {
    return hs[r] - hs[l - 1] * pw[r - l + 1];
}

int get(int s0_s, int s_s, int len) {
    int lt = -1, rt = len + 1;
    while (lt + 1 < rt) {
        int mid = (lt + rt) / 2;
        if (get_hs(hs_s0, s0_s, s0_s + mid - 1) == get_hs(hs_s, s_s, s_s + mid - 1))
            lt = mid;
        else
            rt = mid;
    }
    return lt;
}

bool check(int st) {
    int len = 0;
    for (int i = 1; i <= 3; i++) {
        int z = get(st + len, len + 1, lens - (len + 1) + 1);
        len += z;
        if (len == lens) return true;
        len++;
    }
    if (len == lens) return true;
    int z = get(st + len, len + 1, lens - (len + 1) + 1);
    return len + z == lens;
}

void solve() {
    ans = 0;
    cin >> s0 >> s;
    s0 = "#" + s0;
    s = "#" + s;
    lens0 = s0.size() - 1, lens = s.size() - 1;
    pw[0] = 1;
    for (int i = 1; i <= lens0; i++) hs_s0[i] = hs_s0[i - 1] * base + s0[i];
    for (int i = 1; i <= lens; i++) {
        hs_s[i] = hs_s[i - 1] * base + s[i];
        pw[i] = pw[i - 1] * base;
    }
    for (int i = 1; i + lens - 1 <= lens0; i++) {
        if (check(i)) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
		solve();
	}
    return 0;
}