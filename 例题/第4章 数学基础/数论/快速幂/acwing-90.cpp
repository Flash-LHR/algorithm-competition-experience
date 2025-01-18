// 方法一
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll qkm(ll a, ll b, ll p) {
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % p;
        }
        a = (a * 2) % p;
        b >>= 1;
    }
    return ans;
}


int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << qkm(a, b, p) << endl;
    return 0;
}


// 方法二
#include <bits/stdc++.h>

using namespace std;

long long mul(long long a, long long b, long long m) {
    unsigned long long c =
        (unsigned long long)a * b -
        (unsigned long long)((long double)a / m * b + 0.5L) * m;
    if (c < m) return c;
    return c + m;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    return 0;
}
