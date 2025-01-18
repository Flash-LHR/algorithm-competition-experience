#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

inline int CharIdx(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    }
    if (ch == '.') {
        return 26;
    }
    return 27;
}

int tot_num = 0;

class Trie {
 private:
    vector<Trie*> nxt;
    vector<pair<int, int>> str_ch;
    bool isBad;
 public:
    Trie() : isBad(false), nxt(vector<Trie*>(28, nullptr)) {}

    void Insert(string &s) {
        Trie *now = this;
        for (auto ch : s) {
            if (!now->nxt[CharIdx(ch)]) {
                now->nxt[CharIdx(ch)] = new Trie();
            }
            now = now->nxt[CharIdx(ch)];
        }
    }

    void InitStrCh(vector<string> &str) {
        for (int i = 0; i < str.size(); i++) {
            auto first_ch = str[i][0];
            auto trie_node = this->nxt[CharIdx(first_ch)];
            if (trie_node->str_ch.empty()) {
                ++tot_num;
            }
            trie_node->str_ch.push_back(make_pair(i, 0));
        }
    }

    void DelStr(vector<string> &str, int index) {
        Trie *now = this;
        for (auto ch : str[index]) {
            now = now->nxt[CharIdx(ch)];
            if (now->isBad) {
                continue;
            }
            now->isBad = true;
            if (!now->str_ch.empty()) {
                for (auto &pr : now->str_ch) {
                    if (pr.first == index) {
                        continue;
                    }
                    Trie *nxt_node = now->nxt[CharIdx(str[pr.first][pr.second + 1])];
                    if (nxt_node->str_ch.empty()) {
                        ++tot_num;
                    }
                    nxt_node->str_ch.push_back(make_pair(pr.first, pr.second + 1));
                }
                now->str_ch.clear();
                --tot_num;
            }
        }
    }
};

class Solution {
 public:
    vector<int> solve(vector<string> &str) {
        vector<int> ans(str.size());
        tot_num = 0;
        Trie *root = new Trie();
        for (auto &s : str) {
            root->Insert(s);
        }
        root->InitStrCh(str);
        for (int i = str.size() - 1; i > 0; i--) {
            ans[i] = tot_num;
            root->DelStr(str, i);
        }
        ans[0] = tot_num;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    Solution solution;
    vector<int> ans = solution.solve(str);
    for (auto x : ans) {
        cout << x << "\n";
    }
    return 0;
}