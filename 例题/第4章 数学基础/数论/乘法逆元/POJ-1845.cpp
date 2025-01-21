// 方法一
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int Mod = 9901;

int prime[32], num[32];
int cnt;

void getPrime(int n) {
    int m = sqrt(n + 0.5);
    cnt = 0;
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            prime[cnt] = i;
            while (n % i == 0) {
                num[cnt]++;
                n /= i;
            }
            cnt++;
        }
    }
    if (n > 1) prime[cnt] = n, num[cnt++] = 1;
}

ll qkp(ll x, ll n, ll p) {
    x %= p;
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}

ll cal(ll x, ll n) {
    if (n == 0) return 1;
    ll ans = 0;
    if (n & 1) {
        ans = (qkp(x, n / 2 + 1, Mod) + 1) * cal(x, n / 2);
    } else {
        ans = (qkp(x, n / 2 + 1, Mod) + 1) * cal(x, n / 2 - 1) % Mod + qkp(x, n / 2, Mod);
    }
    return ans % Mod;
}

int main() {
    ll A, B;
    cin >> A >> B;
    getPrime(A);
    ll ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans = (ans * cal(prime[i], B * num[i])) % Mod;
    }
    cout << ans << endl;
    return 0;
}


// 方法二
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int Mod = 9901;

int prime[32], num[32];
int cnt;

void getPrime(int n) {
    int m = sqrt(n + 0.5);
    cnt = 0;
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            prime[cnt] = i;
            while (n % i == 0) {
                num[cnt]++;
                n /= i;
            }
            cnt++;
        }
    }
    if (n > 1) prime[cnt] = n, num[cnt++] = 1;
}

ll qkp(ll x, ll n, ll p) {
    x %= p;
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}

ll inv(ll x, ll p) {
    return qkp(x, p - 2, p);
}

ll cal(ll p, ll n) {
    if ((p - 1) % 9901 == 0) {
        return n % Mod;
    }
    return (qkp(p, n, Mod) - 1 + Mod) % Mod * inv(p - 1, Mod) % Mod;
}

int main() {
    ll A, B;
    cin >> A >> B;
    getPrime(A);
    ll ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans = (ans * cal(prime[i], B * num[i] + 1)) % Mod;
    }
    cout << ans << endl;
    return 0;
}