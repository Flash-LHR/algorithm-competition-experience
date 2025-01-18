#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int n, m, tot;
int head[N], ver[N * 2], edge[N * 2], nxt[N * 2];
double f[N];
int din[N], dinb[N];
int q[N];

void add(int a, int b, int c) {
	ver[tot] = b, edge[tot] = c, nxt[tot] = head[a], head[a] = tot++;
}

void topsort() {
	f[n] = 0;
	int hh = 0, tt = -1;
	q[++tt] = n;
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = head[t]; ~i; i = nxt[i]) {
			int j = ver[i];
			f[j] += (f[t] + edge[i]) / dinb[j];
			if (--din[j] == 0) {
				q[++tt] = j;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(b, a, c);
		din[a]++, dinb[a]++;
	}
	topsort();
	printf("%.2lf", f[1]);
	return 0;
}