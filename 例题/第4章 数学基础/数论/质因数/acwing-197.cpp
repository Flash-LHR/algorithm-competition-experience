#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;

bool vis[maxn];
vector<int> prime;

void euler(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; prime[j] <= n / i; j++) {
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int calc(int n, int p) {
    int sum = 0;
    while (n > 0) {
        sum += n / p;
        n /= p;
    }
    return sum;
}


int main() {
    int n;
    cin >> n;
    euler(n);
    for (auto &p : prime) {
        cout << p << " " << calc(n, p) << "\n";
    }
    return 0;
}