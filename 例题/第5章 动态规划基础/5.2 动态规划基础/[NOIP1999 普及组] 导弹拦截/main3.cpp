#include <bits/stdc++.h>
using namespace std;

int lis1(const vector<int>& v) {
    multiset<int> st;
    st.insert(v[0]);
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] <= *st.begin()) st.insert(v[i]);
        else st.erase(--st.lower_bound(v[i])), st.insert(v[i]);
    }
    return st.size();
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