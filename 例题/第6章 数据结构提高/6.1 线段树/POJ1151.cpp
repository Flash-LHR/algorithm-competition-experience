#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 205;
typedef long long ll;

struct L
{
    double x, y1, y2, flag;
    L(double X = 0, double Y1 = 0, double Y2 = 0, double T = 0)
    {
        x = X, y1 = Y1, y2 = Y2, flag = T;
    }
} line[N];

struct T
{
    int l, r;
    double len;
    int lazy;
} tree[N * 4];

bool cmp(L a, L b)
{
    return a.x < b.x;
}

int n, idx, ans, cnt;
double x1, x2, y1, y2;
double seg[N];
map<double, int> mp;

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].len = 0;
    tree[x].lazy = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
}

void update(int x)
{
    if (tree[x].lazy)
        tree[x].len = seg[tree[x].r + 1] - seg[tree[x].l];
    else if (tree[x].l == tree[x].r)
        tree[x].len = 0;
    else
        tree[x].len = tree[x * 2].len + tree[x * 2 + 1].len;
}

void change(int x, int l, int r, int k)
{
    if (l <= tree[x].l && tree[x].r <= r)
    {
        tree[x].lazy += k;
        update(x);
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (l <= mid)
        change(x * 2, l, r, k);
    if (r > mid)
        change(x * 2 + 1, l, r, k);
    update(x);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n)
    {
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            line[++cnt] = L(x1, y1, y2, 1);
            seg[cnt] = y1;
            line[++cnt] = L(x2, y1, y2, -1);
            seg[cnt] = y2;
        }
        sort(line + 1, line + 1 + cnt, cmp);
        sort(seg + 1, seg + 1 + cnt);
        int m = unique(seg + 1, seg + 1 + cnt) - (seg + 1);
        for (int i = 1; i <= m; i++)
            mp[seg[i]] = i;
        build(1, 1, m);
        double ans = 0;
        for (int i = 1; i < cnt; i++)
        {
            int L = mp[line[i].y1], R = mp[line[i].y2] - 1;
            change(1, L, R, line[i].flag);
            ans += tree[1].len * (line[i + 1].x - line[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++idx, ans);
        cin >> n;
    }
    return 0;
}