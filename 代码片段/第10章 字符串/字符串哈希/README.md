```c++
ll Base = 131;
ll Mod1 = 19260817, Mod2 = 19660813;
 
pair<ll, ll> getHash(string &s) {
    ll hashe1 = 0, hashe2 = 0;
    for (int i = 0; i < s.size(); i++) {
        hashe1 = (hashe1 * Base + s[i]) % Mod1;
        hashe2 = (hashe2 * Base + s[i]) % Mod2;
    }
    return make_pair(hashe1, hashe2);
}
```

```c++
ull Base = 131;
ull h[maxn], bn[maxn];
 
int containSubstr(string &s, string &t) {
    int n = s.size(), m = t.size();
    if (n < m) return -1;
 
    bn[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * Base + s[i - 1];
        bn[i] = bn[i - 1] * Base;
    }
 
    ull key = 0;
    for (int i = 0; i < m; i++) key = key * Base + t[i];
 
    for (int i = 1; i <= n - m + 1; i++) {
        ull curHash = h[i + m - 1] - h[i - 1] * bn[m];
        if (curHash == key) return i - 1;
    }
    return -1;
}
```

