int ans = 0;
for (int i = l; i <= r; i++)
    if (check(i)) ans++;

// 20是数位最大长度
int num[20];
// 不同题目状态不同
// f[i][j]表示在没有数位上界限制的条件下，数字高位状态为j的i位数字的个数
int f[20][state];

int dfs(int pos, int state, bool lim, bool lead) {
    // 递归边界，最低位是0，pos==-1则说明枚举完了一个数
    if (pos == -1) return 1;
    // 记忆化
    if (!lim && !lead && ~f[pos][state]) return f[pos][state];
    // 计算当前数位能填的数字的上界
    int up = (lim ? num[pos] : 9), res = 0;
    for (int i = 0; i <= up; i++) {
        res += dfs(pos - 1, /* 状态转移 */, lim && i == up, lead && i == 0);
    }
    // 记录状态
    if (!lim && !lead) f[pos][state] = res;
    return res;
}

int cal(int n) {
    int pos = 0;
    // 数位分解到pos数字
    while (n) {
        num[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1, /* 初始状态 */, true, true);
}

int main() {
    int l, r; scanf("%d %d", &l, &r);
    printf("%d\n", cal(r) - cal(l - 1));
    return 0;
}