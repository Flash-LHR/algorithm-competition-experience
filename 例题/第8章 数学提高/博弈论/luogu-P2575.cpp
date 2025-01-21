#include <bits/stdc++.h>

using namespace std;

bitset<25> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 1, y; i <= n; i++) {
            vis.reset();
            cin >> m;
            while (m--) {
                cin >> y;
                vis[y] = 1;
            }
            int cnt = 0, num = 0;
            for (int j = 20; j >= 0; j--) {
                if (!vis[j]) {
                    if (cnt) ans ^= num;
                    cnt ^= 1;
                    num = 0;
                } else num++;
            }
        }
        if (ans) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
