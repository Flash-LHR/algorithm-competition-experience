#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;

int n;

struct node {
    int a, b;
} t[maxn];

bool cmp(node &p, node &q) {
    return p.a * p.b < q.a * q.b;
}

struct BigInt {
    int a[8005];
    int len;

    BigInt() {
        memset(a, 0, sizeof a);
        len = 0;
    }

    BigInt(int x) {
        if (x == 0)
            a[0] = 0, len = 1;
        else {
            len = 0;
            while (x) {
                a[len++] = x % 10;
                x /= 10;
            }
        }
    }

    BigInt operator*(const BigInt &T) const {
        BigInt ans;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < T.len; j++) {
                ans.a[i + j] += a[i] * T.a[j] % 10;
                ans.a[i + j + 1] += a[i] * T.a[j] / 10;
            }
        }
        for (int i = 0; i < len + T.len; i++) {
            ans.a[i + 1] += ans.a[i] / 10;
            ans.a[i] %= 10;
        }
        ans.len = len + T.len;
        while (ans.a[ans.len - 1] == 0 && ans.len > 1) ans.len--;
        return ans;
    }

    BigInt operator/(const int &x) const {
        BigInt ans;
        int pre = 0;
        for (int i = len - 1; i >= 0; i--) {
            ans.a[i] = (a[i] + pre * 10) / x;
            pre = a[i] + pre * 10 - ans.a[i] * x;
        }
        ans.len = len;
        while (ans.a[ans.len - 1] == 0 && ans.len > 1) ans.len--;
        return ans;
    }

    bool operator<(const BigInt &T) const {
        if (len > T.len) return false;
        if (len < T.len) return true;
        for (int i = len - 1; i >= 0; i--) {
            if (a[i] < T.a[i])
                return true;
            else if (a[i] > T.a[i])
                return false;
        }
        return false;
    }

    BigInt &operator=(const BigInt &T) {
        len = T.len;
        for (int i = 0; i < len; i++) a[i] = T.a[i];
        return *this;
    }

    void print() {
        for (int i = len - 1; i >= 0; i--) cout << a[i];
        cout << "\n";
    }
};

int main() {
    cin >> n;
    cin >> t[0].a >> t[0].b;
    for (int i = 1; i <= n; i++) cin >> t[i].a >> t[i].b;
    sort(t + 1, t + n + 1, cmp);
    BigInt res(t[0].a);
    BigInt ans(0);
    for (int i = 1; i <= n; i++) {
        BigInt cur = res;
        cur = cur / t[i].b;
        if (ans < cur) ans = cur;
        res = res * t[i].a;
    }
    ans.print();
    return 0;
}