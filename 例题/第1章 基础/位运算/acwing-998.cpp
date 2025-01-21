#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;

struct node {
    int op;   // 1 -- OR; 2 -- XOR; 3 -- AND
    int t;
} opt[maxn];

int n, m;
string s;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s >> opt[i].t;
        if (s[0] == 'O')
            opt[i].op = 1;
        else if (s[0] == 'X')
            opt[i].op = 2;
        else
            opt[i].op = 3;
    }
    int maxBit = log2(m), val = 0, ans = 0;
    for (int i = maxBit; i >= 0; i--) {
        int b0 = 0, b1 = 1;
        for (int j = 1; j <= n; j++) {
            if (opt[j].op == 1) {
                b0 |= ((opt[j].t >> i) & 1);
                b1 |= ((opt[j].t >> i) & 1);
            } else if (opt[j].op == 2) {
                b0 ^= ((opt[j].t >> i) & 1);
                b1 ^= ((opt[j].t >> i) & 1);
            } else {
                b0 &= ((opt[j].t >> i) & 1);
                b1 &= ((opt[j].t >> i) & 1);
            }
        }
        if (b1 > b0 && val + (1 << i) <= m) val += 1 << i;
    }
    for (int j = 1; j <= n; j++) {
        if (opt[j].op == 1)
            val |= opt[j].t;
        else if (opt[j].op == 2)
            val ^= opt[j].t;
        else
            val &= opt[j].t;
    }
    cout << val << endl;
    return 0;
}