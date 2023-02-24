#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int f[M + 5];

int lis1(const vector<int>& v) {
    int n = 0;
    f[0] = inf;
    for (const int &x: v) {
        if (x <= f[n]) f[++n] = x;
        else {
            int l = 1, r = n, mid;
            while (l < r) {
                mid = (l + r) >> 1;
                if (f[mid] < x) r = mid;
                else l = mid + 1;
            }
            f[r] = x;
        }
    }
    return n;
}

int lis2(const vector<int>& v) {
    set<int> st;
    st.insert(v[0]);
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > *--st.end()) st.insert(v[i]);
        else st.erase(st.lower_bound(v[i])), st.insert(v[i]);
    }
    return st.size();
}

void work() {
    vector<int> v;
    for (int x; ~scanf("%d", &x);) v.push_back(x);
    printf("%d\n", lis1(v));
    printf("%d\n", lis2(v));
}

int main() {
    work();
    return 0;
}