// 做法一
#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 10;

int cnt;
bool st[N], vis[N];
int sum[N], primes[N];

void init() {
    for (int i = 2; i <= N; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= N / i; j++) {
            st[primes[j] * i] = true;
            if (!st[i]) vis[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1];
        if (vis[i]) sum[i]++;
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}


// 做法二
#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 10;

int cnt;
bool vis[N];
int sum[N], primes[N], minp[N];

void init() {
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= N / i; j++) {
            vis[primes[j] * i] = true;
			minp[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1];
		if (vis[i] && !vis[i / minp[i]]) {
			sum[i]++;
		}
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}
