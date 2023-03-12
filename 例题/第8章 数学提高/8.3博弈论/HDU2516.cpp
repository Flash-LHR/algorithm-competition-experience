#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    while (n) {
        ll x = 1, y = 1;
        while (y < n) x = x + y, swap(x, y);
        if (y == n) puts("Second win");
        else puts("First win");
        scanf("%lld", &n);
    }
    return 0;
}
