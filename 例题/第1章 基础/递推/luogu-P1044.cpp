// 做法一
#include <bits/stdc++.h>

using namespace std;

int f[20][20];

// 栈里有i个，队列有j个
int dfs(int i, int j) {
	if (f[i][j]) return f[i][j];
	if (j == 0) return 1;
	if (i > 0) f[i][j] += dfs(i - 1, j);
	f[i][j] += dfs(i + 1, j - 1);
	return f[i][j];
}

int main() {
	int n;
	cin >> n;
	cout << dfs(0, n) << endl;
	return 0;
}


// 做法二：
#include <bits/stdc++.h>

using namespace std;

int f[20];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i] += f[j - 1] * f[i - j];
		}
	}
	cout << f[n] << endl;
	return 0;
}