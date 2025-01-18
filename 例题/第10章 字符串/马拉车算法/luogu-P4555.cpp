#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int rad[maxn];
int L[maxn], R[maxn];

int manacher(string str) {
    string s = "#";
    for(int i = 0; i < str.size(); i++) {
        s += str[i];
        s += '#';
    }
    int n = s.size();
    int l = 0, mid = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            int symPos = mid - (i - mid);
            rad[i] = min(r - i, rad[symPos]);
        } else {
            rad[i] = 1;
        }
        int j = i - rad[i], k = i + rad[i];
        while(j >= 0 && k < n && s[j] == s[k]) {
            j--, k++;
        }
        j++, k--;
        rad[i] = k - i;
        if(k > r) {
            l = j;
            r = k;
            mid = (l + r) >> 1;
        }

        L[i - rad[i]] = max(L[i - rad[i]], rad[i]);
        R[i + rad[i]] = max(R[i + rad[i]], rad[i]);
    }

    int ans = 0;

    for (int i = n - 1; i >= 0; i -= 2) R[i] = max(R[i], R[i + 2] - 2);
	for (int i = 0; i < n; i += 2) L[i] = max(L[i], L[i - 2] - 2);

	for (int i = 0; i <= n; i += 2) {
        if (R[i] && L[i]) {
            ans = max(ans, L[i] + R[i]);
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << manacher(s) << endl;
    return 0;
}