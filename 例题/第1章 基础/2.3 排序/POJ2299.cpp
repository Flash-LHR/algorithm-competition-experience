#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn], t[maxn];
long long cnt = 0;

void merge_sort(int x, int y)
{
    if (y - x > 1)
    {
        int mid = x + (y - x) / 2;
        int p = x, q = mid, i = x;
        merge_sort(x, mid);
        merge_sort(mid, y);
        while (p < mid || q < y)
        {
            if (q >= y || (p < mid && a[p] <= a[q]))
                t[i++] = a[p++];
            else
            {
                t[i++] = a[q++];
                cnt += mid - p;
            }
        }
        for (int i = x; i < y; i++)
            a[i] = t[i];
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        cnt = 0;
        merge_sort(0, n);
        printf("%lld\n", cnt);
    }
    return 0;
}
