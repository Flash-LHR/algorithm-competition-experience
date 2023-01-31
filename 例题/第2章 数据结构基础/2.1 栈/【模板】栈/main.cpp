#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int M = (int)1e6;

ull st[M + 5], tp;  // tp记录栈顶

void work() {
  tp = 0;
  int n;
  scanf("%d", &n);
  char op[10];
  ull x;
  for (int i = 1; i <= n; i++) {
    scanf("%s", op);
    if (op[0] == 'p' && op[1] == 'u') {  // push(x)
      scanf("%llu", &x);
      st[++tp] = x;
    } else if (op[0] == 'p') {  // pop()
      if (tp)
        tp--;
      else
        puts("Empty");
    } else if (op[0] == 'q') {  // query()
      if (tp)
        printf("%llu\n", st[tp]);
      else
        puts("Anguei!");
    } else  // size()
      printf("%d\n", tp);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ca++) {
    work();
  }
  return 0;
}