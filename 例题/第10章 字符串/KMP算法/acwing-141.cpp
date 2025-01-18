#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 1e6 + 10;

int n;
char s[maxn];
int Next[maxn];

void getNext() {
    Next[0] = 0;
    int now = 0;
    for(int i = 1; i < n; i++) {
        while(now && s[now] != s[i]) now = Next[now - 1];
        if(s[now] == s[i]) Next[i] = ++now;
        else Next[i] = 0;
    }
}

int main() {
    int kase = 0;
    while(~scanf("%d", &n) && n) {
        scanf("%s", s);
        getNext();
        printf("Test case #%d\n", ++kase);
        for(int i = 2; i <= n; i++) {
            if(i % (i - Next[i - 1]) == 0 && i / (i - Next[i - 1]) > 1) {
                printf("%d %d\n", i, i / (i - Next[i - 1]));
            }
        }
        puts("");
    }
    return 0;
}