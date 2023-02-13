#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, sum, num, flag;
int a[65], vis[65];
bool cmp(int x, int y)
{
    return x > y;
}
void dfs(int num1, int len, int pos)
{
    if (flag)
    {
        return;
    }
    if (num1 == num)
    {
        flag = 1;
        return;
    }
    for (int i = pos; i < n; i++)
    {
        if (vis[i])
            continue;
        if (sum / num == a[i] + len)
        {
            vis[i] = 1;
            // num++运算后num实际取值为num+1，但显示的结果仍num,
            // 下次运算时用num+1的取值运算，但显示num+1的值；
            // num=num+1的值显示和实际的都为num+1.
            dfs(num1 + 1, 0, 0);
            vis[i] = 0;
            return;
        }
        else if (sum / num > a[i] + len)
        {
            vis[i] = 1;
            dfs(num1, len + a[i], i + 1);
            vis[i] = 0;
            if (len == 0)
                return;
            while (a[i] == a[i + 1])
                i++;
        }
    }
}
int main(int argc, char **argv)
{
    while (scanf("%d", &n) && n)
    {
        sum = 0, flag = 0;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n, cmp);
        for (int i = a[0]; i <= sum; i++)
        {
            if (sum % i)
                continue;
            num = sum / i;
            dfs(0, 0, 0);
            if (flag)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
