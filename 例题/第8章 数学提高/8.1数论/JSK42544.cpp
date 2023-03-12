#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

ll x, y, a[maxn];

struct PollardRho {
  const static int maxm = 1e6 + 16;
  ll prime[maxm], p[maxm], fac[maxm], sz, cnt;
  inline ll mul(ll a, ll b, ll mod) {
      if (mod <= 1000000000) return a * b % mod;
      return (a * b - (ll) ((long double) a / mod * b + 1e-8) * mod + mod) % mod;
  }
  void init(int maxn) {
      int tot = 0;
      sz = maxn - 1;
      for (int i = 1; i <= sz; ++i) p[i] = i;
      for (int i = 2; i <= sz; ++i) {
          if (p[i] == i) prime[tot++] = i;
          for (int j = 0; j < tot && 1ll * i * prime[j] <= sz; ++j) {
              p[i * prime[j]] = prime[j];
              if (i % prime[j] == 0) break;
          }
      }
  }
  ll powl(ll a, ll x, ll mod) {
      ll res = 1LL;
      while (x) {
          if (x & 1) res = mul(res, a, mod);
          a = mul(a, a, mod);
          x >>= 1;
      }
      return res;
  }
  bool check(ll a, ll n) {                       //二次探测原理检验n
      ll t = 0, u = n - 1;
      while (!(u & 1)) t++, u >>= 1;
      ll x = powl(a, u, n), xx = 0;
      while (t--) {
          xx = mul(x, x, n);
          if (xx == 1 && x != 1 && x != n - 1) return false;
          x = xx;
      }
      return xx == 1;
  }
  bool miller(ll n, int k) {
      if (n == 2) return true;
      if (n < 2 || !(n & 1)) return false;
      if (n <= sz) return p[n] == n;
      for (int i = 0; i <= k; ++i) {               //测试k次
          if (!check(rand() % (n - 1) + 1, n)) return false;
      }
      return true;
  }
  inline ll gcd(ll a, ll b) {
      return b == 0 ? a : gcd(b, a % b);
  }
  inline ll Abs(ll x) {
      return x < 0 ? -x : x;
  }
  ll Pollard_rho(ll n) {                  //基于路径倍增的Pollard_Rho算法
      ll s = 0, t = 0, c = rand() % (n - 1) + 1, v = 1, ed = 1;
      while (1) {
          for (int i = 1; i <= ed; ++i) {
              t = (mul(t, t, n) + c) % n;
              v = mul(v, Abs(t - s), n);
              if (i % 127 == 0) {
                  ll d = gcd(v, n);
                  if (d > 1) return d;
              }
          }
          ll d = gcd(v, n);
          if (d > 1) return d;
          s = t;
          v = 1;
          ed <<= 1;
      }
  }
  void getfactor(ll n) {                          //得到所有的质因子(可能有重复的)
      if (n <= sz) {
          while (n != 1) fac[cnt++] = p[n], n /= p[n];
          return;
      }
      if (miller(n, 6)) fac[cnt++] = n;
      else {
          ll d = n;
          while (d >= n) d = Pollard_rho(n);
          getfactor(d);
          getfactor(n / d);
      }
  }
  ll cal(ll n, ll x) {
      ll num = 0;
      while (n) {
          num += n / x;
          n = n / x;
      }
      return num;
  }
  ll solve(int n, ll x, ll y) {
      map<ll, ll> mp;
      ll ans = 4e18;
      cnt = 0;
      getfactor(x);
      for (int i = 0; i < cnt; ++i) mp[fac[i]]++;
      map<ll, ll>::iterator it = mp.begin();
      while (it != mp.end()) {
          ll num = 0;
          for (int i = 1; i <= n; ++i) {
              num += cal(a[i], it->first);
          }
          ans = min(ans, (cal(y, it->first) - num) / it->second);
          it++;
      }
      return ans;
  }
} Q;

int main() {
    Q.init(100000);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld %lld", &n, &x, &y);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", a + i);
        printf("%lld\n", Q.solve(n, x, y));
    }
    return 0;
}
