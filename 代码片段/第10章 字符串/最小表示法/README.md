```c++
string minRepr(string &src) {
    int n = src.size();
    string s = src + src;
    int i = 0, j = 1, k;
    while (i < n && j < n) {
        for (k = 0; k < n && s[i + k] == s[j + k]; k++);
        if (k == n) break;
        if (s[i + k] > s[j + k]) {
            i += k + 1;
            if (i == j) ++i;
        } else {
            j += k + 1;
            if (i == j) ++j;
        }
    }
    return s.substr(min(i, j), n);
}
```

