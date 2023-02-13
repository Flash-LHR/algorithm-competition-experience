#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;
int path[N], m;
bool b[N];

void dfs(int x)
{
    if (x == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        return; // 回溯
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i] != true)
        {
            path[x] = i;
            b[i] = true;
            dfs(x + 1);
            b[i] = false;
        }
    }
    return; // 个人感觉加上更容易理解，目的是回溯
}

int main()
{
    cin >> m;
    dfs(0);
    return 0;
}