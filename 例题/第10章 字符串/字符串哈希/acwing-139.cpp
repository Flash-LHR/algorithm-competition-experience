// 方法一
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int N = 2000010, P = 131;

char s[N];
ull h1[N], h2[N], p[N];

ull get(ull h[], ull l, ull r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int cnt = 0;
    while (scanf("%s", s + 1) && strcmp(s + 1, "END")) {
        int n = strlen(s + 1) * 2;
        for (int i = n; i; i -= 2) {
            s[i] = s[i / 2];
            s[i - 1] = 'z' + 1;
        }
        p[0] = 1;
        for (int i = 1, j = n; i <= n; i++, j--) {
            h1[i] = h1[i - 1] * P + s[i] - 'a' + 1;
            h2[i] = h2[i - 1] * P + s[j] - 'a' + 1;
            p[i] = p[i - 1] * P;
        }
        ull ans = 0;
        for (int i = 1; i <= n; i++) {
            ull l = 0, r = min(i - 1, n - i);
            while (l < r) {
                ull mid = (l + r + 1) / 2;
                if (get(h1, i - mid, i - 1) != get(h2, n - (i + mid) + 1, n - i))
                    r = mid - 1;
                else
                    l = mid;
            }
            if (s[i - l] <= 'z')
                ans = max(ans, l + 1);
            else
                ans = max(ans, l);
        }
        printf("Case %d: %d\n", ++cnt, ans);
    }
    return 0;
}



// 方法二
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e6 + 10;

int n;
char s[maxn];
int R[maxn];
ull base = 131;
ull pre[maxn], suf[maxn], b[maxn];

int longestPalindrome() {
    int ans = 1;
    R[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = i - R[i - 1] - 1;
        if (j >= 1 && s[j] == s[i]) R[i] = R[i - 1] + 2;
        else {
            for (int k = j + 1; k <= i; k++) {
                ull hash1 = pre[i] - pre[k - 1] * b[i - k + 1];
                ull hash2 = suf[k] - suf[i + 1] * b[i - k + 1];
                if (hash1 == hash2) {
                    R[i] = i - k + 1;
                    break;
                }
            }
        }
        ans = max(ans, R[i]);
    }
    return ans;
}

int main() {
    b[0] = 1;
    for (int i = 1; i < maxn; i++) b[i] = b[i - 1] * base;
    for (int k = 1; ; k++) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        if (n == 3 && s[1] == 'E' && s[2] == 'N' && s[3] == 'D') break;
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] * base + s[i];
        for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] * base + s[i];
        printf("Case %d: %d\n", k, longestPalindrome());
    }
    return 0;
}