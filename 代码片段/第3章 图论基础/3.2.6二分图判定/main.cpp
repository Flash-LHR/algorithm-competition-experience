#include<cstring>
#include<iostream>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int head[N], e[M], Next[M], idx;
int color[N];
int n, m;

void add(int a, int b){
    e[idx] = b;
    Next[idx] = head[a];
    head[a] = idx++;
}

bool dfs(int u, int c){
    color[u] = c; // 记录颜色

    for (int i = head[u]; i != -1; i = Next[i]){
        int j = e[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
            return false; 
    }

    return true;
}

int main(){
    cin >> n >> m;
    memset(head, -1, sizeof(head));

    while (m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    // 遍历判断所有点，染色
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}
