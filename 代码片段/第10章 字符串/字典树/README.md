```c++
const int S = 26;
const int MAXN = N * L;
 
struct Trie {
    int nxt[MAXN][S];
    bool exist[MAXN];
    int cnt = 0;
 
    void insert(char *s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!nxt[p][c]) nxt[p][c] = ++cnt;
            p = nxt[p][c];
        }
        exist[p] = true;
    }
 
    bool find(char *s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!nxt[p][c]) return false;
            p = nxt[p][c];
        }
        return exist[p];
    } 
};
```

