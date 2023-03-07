#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int a[N];
int main()
{
    int t;
    while (scanf("%d", &t) != EOF)
    {
        while (t--)
        {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
                scanf("%d", &a[i]);
            sort(a + 1, a + 1 + n);

            int sum = 0;
            bool flag = true;
            for (int i = 1; i <= n; i++)
            {
                sum += a[i];
                if (i <= n - 1)
                {
                    if (sum < i * (i - 1))
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    if (sum != i * (i - 1))
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag)
                printf("T\n");
            else
                printf("F\n");
        }
    }
    return 0;
}