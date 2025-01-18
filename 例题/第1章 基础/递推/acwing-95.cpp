#include <bits/stdc++.h>
using namespace std;

int a[10][10], b[10][10];
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool judge() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++) {
            if (b[i][j] == 0) return 0;
        }
    return 1;
}

bool check(int x, int y) {
    return x >= 1 && x <= 5 && y >= 1 && y <= 5;
}

void click(int r, int c) {
    b[r][c] ^= 1;
    for (int i = 0; i < 4; i++) {
        int x = r + dx[i], y = c + dy[i];
        if (check(x, y)) {
            b[x][y] ^= 1;
        }
    }
}

int main() {
    int n;
    string str;
    cin >> n;
    while (n--) {
        for (int i = 1; i <= 5; i++) {
            cin >> str;
            for (int j = 1; j <= 5; j++) {
                a[i][j] = str[j - 1] - '0';
            }
        }
        int up = 1 << 5, ans = 1e9;
        for (int s = 0; s < up; s++) {
            memcpy(b, a, sizeof a);
            int cnt = 0;
            for (int k = 0; k <= s; k++) {
                if (s & (1 << k)) {
                    cnt++;
                    click(1, k + 1);
                }
            }
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 5; j++) {
                    if (b[i][j] == 0) {
                        cnt++;
                        click(i + 1, j);
                    }
                }
            }
            if (judge()) ans = min(ans, cnt);
        }
        if (ans <= 6)
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}