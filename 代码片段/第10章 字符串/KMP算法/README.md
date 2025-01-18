```c++
int Next[maxn];
 
int kmp(string &s, string &t) {
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) i++, j++;
        else {
            if (j > 0) j = Next[j - 1];
            else i++;
        }
    }
    return j == m ? i - m + 1 : -1;
}
```

```c++
int Next[maxn];
 
void GetNext(string &t) {
    int m = t.size();
    Next[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && t[j] != t[i]) j = Next[j - 1];
        if (t[j] == t[i]) Next[i] = ++j;
        else Next[i] = 0;
    }
}
```

```c++
int Next[maxn];
 
void GetNext(string &t) {
    int m = t.size();
    Next[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && t[j] != t[i]) j = Next[j - 1];
        if (t[j] == t[i]) Next[i] = ++j;
        else Next[i] = 0;
    }
}
 
vector<int> Kmp(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<int> ans;
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != t[j]) j = Next[j - 1];
        if (s[i] == t[j]) j++;
        if (j == m) {
            ans.push_back(i - m + 1);
            j = Next[j - 1];
        } 
    }
    return ans;
}
```

