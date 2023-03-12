#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int M = int(1e5);

vector<int> v[M + 5];
db f[M + 5];

void init() {
    for (int i = 1; i <= M; i++)
        for (int j = i; j <= M; j += i)
            v[j].push_back(i);
    for (int i = 2; i <= M; i++) {
        for (const int &j: v[i]) if (i != j) f[i] += f[j];
        f[i] = (f[i] + v[i].size()) / (v[i].size() - 1.0);
    }
}

void work() {
    int n; scanf("%d", &n);
    printf("%.12f\n", f[n]);
}

int main() {
    init();
    int T; scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
        printf("Case %d: ", ca);
        work();
    }
    return 0;
}