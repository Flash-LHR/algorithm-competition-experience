#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 1e7 + 10;
int n, a[N], s[N], l[N], r[N];
ll L, R;

int main()
{
    scanf("%d", &n);
    for (int i = 1, pos = 0, top = 0; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        pos = top;
        while (pos && a[s[pos]] > a[i])
            pos--;
        if (pos)
            r[s[pos]] = i;
        if (pos < top)
            l[i] = s[pos + 1];
        s[top = ++pos] = i;
    }
    for (int i = 1; i <= n; ++i)
        L ^= 1LL * i * (l[i] + 1), R ^= 1LL * i * (r[i] + 1);
    printf("%lld %lld", L, R);
    return 0;
}