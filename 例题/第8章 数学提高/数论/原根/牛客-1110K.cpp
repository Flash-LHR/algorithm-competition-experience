#include <iostream>
#include <bitset>
 
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int maxn = 2e6 + 10;
 
int n, r;
int a[maxn], p[maxn];
bitset<2016> d;
bool vis[maxn];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int res = 1;
    for (int i = 0; i < 2016; i++) {
        p[res] = i;
        res = res * 5 % 2017;
    }
    while (cin >> n >> r) {
        d.reset();
        d.set(p[1]);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            d ^= (d << p[a[i]]) ^ (d >> (2016 - p[a[i]]));
        }
        cout << d[p[r]] << endl;
    }
    return 0;
}
