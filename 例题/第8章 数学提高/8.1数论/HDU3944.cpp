#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int maxn = 1e4 + 10;

vector<int> prime;
bool is_prime[maxn];
unordered_map<int, int> mp;
ll fac[maxn][1300];
int num;

void getPrime() {  //欧拉筛求素数
    memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < maxn; i++) {
        if (is_prime[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && 1LL * i * prime[j] < maxn; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
    //cout<<prime.size()<<endl;
    mp.clear(), num = 0;
    for (auto i : prime) mp[i] = ++num;
}

ll qkp(ll x, ll n, ll p) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}

ll inv(ll x, ll p) {  //求逆元
    return qkp(x, p - 2, p);
}

ll cal(ll n, ll m, ll p) {
    if (m > n) return 0;
    return fac[n][mp[p]] * inv(fac[m][mp[p]], p) % p * inv(fac[n - m][mp[p]], p) % p;
}

ll lucas(ll n, ll m, ll p) {
    if (!m) return 1;
    return cal(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

void init() {
    for (auto p : prime) {
        int j = mp[p];
        fac[0][j] = 1;
        for (int i = 1; i < maxn; i++)
            fac[i][j] = fac[i - 1][j] * i % p;
    }
}

int main() {
    int kase = 0;
    ll n, m, p;
    getPrime();
    init();
    while (scanf("%lld%lld%lld", &n, &m, &p) != EOF) {
        if (m <= n / 2) printf("Case #%d: %lld\n", ++kase, (lucas(n + 1, m, p) + (n - m + p) % p) % p);
        else printf("Case #%d: %lld\n", ++kase, (lucas(n + 1, m + 1, p) + m) % p);
    }
    return 0;
}