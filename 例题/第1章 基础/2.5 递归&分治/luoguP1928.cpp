#include <iostream>
#include <stack>
using namespace std;
const int maxn = 2e5 + 10;

string dfs(string s) {
    string ans = "";
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            stack<char> st;
            int j;
            for (j = i; j < s.size(); j++) {
                if (s[j] == '[')
                    st.push(s[j]);
                else if (s[j] == ']') {
                    st.pop();
                    if (st.empty()) break;
                }
            }
            ans += dfs(s.substr(i + 1, j - i - 1));
            i = j;
        } else {
            if (s[i] >= '0' && s[i] <= '9')
                k = k * 10 + s[i] - '0';
            else
                ans += s[i];
        }
    }
    if (k == 0) k = 1;
    string res = "";
    for (int i = 0; i < k; i++) res += ans;
    return res;
}

// CD[2AB[3XY]C]

int main() {
    string s;
    cin >> s;
    cout << dfs(s) << "\n";
    return 0;
}