```c++
string manacher(string str) {
    string s = "#";
    for (int i = 0; i < str.size(); i++) {
        s += str[i];
        s += '#';
    }
    int n = s.size();
    vector<int> rad(n + 1, 0);
    int l = 0, mid = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int symPos = mid - (i - mid);
            rad[i] = min(r - i, rad[symPos]);
        } else {
            rad[i] = 0;
        }
        int j = i - rad[i], k = i + rad[i];
        while (j >= 0 && k < n && s[j] == s[k]) {
            j--, k++;
        }
        rad[i] = (k - 1) - i;
        if (k > r) {
            l = j - 1;
            r = k - 1;
            mid = (l + r) >> 1;
        }
    }
    int maxlen = 0;
    string ans = "";
    for (int i = 1; i < n; i++) {
        if (rad[i] > maxlen) {
            mid = i;
            maxlen = rad[i];
        }
    }
    for (int i = mid - maxlen; i <= mid + maxlen; i++) {
        if (s[i] != '#') {
            ans += s[i];
        }
    }
    return ans;
}
```

