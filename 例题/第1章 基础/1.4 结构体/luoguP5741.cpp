#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

struct node {
    string name;        // 姓名
    int c, m, e, sum;   // 语文, 数学, 英语, 总成绩
} a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].c >> a[i].m >> a[i].e;
        a[i].sum = a[i].c + a[i].m + a[i].e;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(a[i].c - a[j].c) <= 5 && abs(a[i].m - a[j].m) <= 5 &&
                abs(a[i].e - a[j].e) <= 5 &&
                abs(a[i].sum - a[j].sum) <= 10) {   // 判断是否符合旗鼓相当的对手
                if (a[i].name > a[j].name) {        // 判断字典序
                    cout << a[j].name << " " << a[i].name << "\n";
                } else {
                    cout << a[i].name << " " << a[j].name << "\n";
                }
            }
        }
    }
    return 0;
}