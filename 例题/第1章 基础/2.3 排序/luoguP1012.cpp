#include <algorithm>
#include <iostream>
using namespace std;

string s[200];

bool cmp(string s1, string s2) {
    int len = min(s1.size(), s2.size());
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) return s1[i] > s2[i];
    }
    if (s1.size() < s2.size()) return s1[0] > s2[len];
    return s1[len] > s2[0];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + 1 + n, cmp);
    string ans = "";
    for (int i = 1; i <= n; i++) ans += s[i];
    cout << ans << "\n";
    return 0;
}