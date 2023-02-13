#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;

struct node {
    string name;
    string pos;
    int x, y, pre;

    node() {}

    node(string s1, string s2, int a, int b, int c) {
        name = s1, pos = s2, x = a, y = b, pre = c;
    }
};

int cnt[5] = {2, 4, 7, 25, 200};
string d[5] = {"HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};

node a[200];
vector<node> res, ans;

bool cmp1(node &p, node &q) {
    if (p.x == q.x)
        return p.pre < q.pre;
    else
        return p.x > q.x;
}

int getNum(string s) {
    if (s == "BangZhu")
        return 7;
    else if (s == "FuBangZhu")
        return 6;
    else if (s == "HuFa")
        return 5;
    else if (s == "ZhangLao")
        return 4;
    else if (s == "TangZhu")
        return 3;
    else if (s == "JingYing")
        return 2;
    else
        return 1;
}

bool cmp2(node p, node q) {
    if (getNum(p.pos) == getNum(q.pos)) return p.y == q.y ? p.pre < q.pre : p.y > q.y;
    return getNum(p.pos) > getNum(q.pos);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].pos >> a[i].x >> a[i].y;
        a[i].pre = i;
        if (a[i].pos == "BangZhu" || a[i].pos == "FuBangZhu")
            ans.push_back(a[i]);
        else
            res.push_back(a[i]);
    }
    sort(res.begin(), res.end(), cmp1);
    int k = 0;
    for (auto i : res) {
        i.pos = d[k];
        ans.push_back(i);
        cnt[k]--;
        if (cnt[k] == 0) k++;
    }
    sort(ans.begin(), ans.end(), cmp2);
    for (auto i : ans) {
        cout << i.name << " " << i.pos << " " << i.y << "\n";
    }
    return 0;
}