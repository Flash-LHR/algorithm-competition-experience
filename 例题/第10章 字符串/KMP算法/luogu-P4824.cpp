#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 1e6 + 10;

int next[maxn], pos[maxn];

void get_next(std::string &t) {
	int m = t.size();
	next[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && t[j] != t[i]) j = next[j - 1];
		if (t[i] == t[j]) next[i] = ++j;
		else next[i] = 0;
	}
}

std::string kmp(std::string &s, std::string &t) {
	get_next(t);
	memset(pos, -1, sizeof(pos));
	std::vector<int> stack;
	int n = s.size(), m = t.size();
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != t[j]) j = next[j - 1];
		stack.push_back(i);
		if (s[i] == t[j]) pos[i] = j++;
		if (j == m) {
			while (j > 0) {
				stack.pop_back();
				--j;
			}
			if (!stack.empty()) {
				j = pos[stack.back()] + 1;
			}
		}
	}
	std::string ans;
	for (auto i : stack) ans += s[i];
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::string s, t;
	std::cin >> s >> t;
	std::cout << kmp(s, t) << std::endl;
    return 0;
}