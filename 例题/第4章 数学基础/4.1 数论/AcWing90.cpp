#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll mul(ll a, ll b, ll p) {
    if (p <= 1000000000)
        return a * b % p;
    else if (p <= 1000000000000LL)
        return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
    else {
        ll d = (ll)floor(a * (long double)b / p + 0.5);
        ll ret = (a * b - d * p) % p;
        if (ret < 0) ret += p;
        return ret;
    }
}

int main() {
    ll x, y, p;
    cin >> x >> y >> p;
    cout << mul(x, y, p) << endl;
    return 0;
}