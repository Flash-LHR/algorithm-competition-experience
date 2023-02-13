#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1005;

struct BigInt {
    int a[maxn];
    int len;

    BigInt() {
        len = 1;
        memset(a, 0, sizeof a);
    }

    BigInt(char *s) {
        memset(a, 0, sizeof a);
        len = strlen(s);
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--) a[cnt++] = s[i] - '0';
    }

    BigInt(string s) {
        memset(a, 0, sizeof a);
        len = s.size();
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--) a[cnt++] = s[i] - '0';
    }

    BigInt &operator=(const BigInt &T) {   // 重载赋值运算符，大数之间进行赋值运算
        len = T.len;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < len; i++) a[i] = T.a[i];
        return *this;
    }

    bool operator>(const BigInt &T) const {
        if (len > T.len) return 1;
        if (len < T.len) return 0;
        int cur = len - 1;
        while (a[cur] == T.a[cur] && cur >= 0) cur--;
        if (cur >= 0 && a[cur] > T.a[cur])
            return 1;
        else
            return 0;
    }

    bool operator<(const BigInt &T) const {
        if (len < T.len) return 1;
        if (len > T.len) return 0;
        int cur = len - 1;
        while (a[cur] == T.a[cur] && cur >= 0) cur--;
        if (cur >= 0 && a[cur] < T.a[cur])
            return 1;
        else
            return 0;
    }

    bool operator==(const BigInt &T) const {
        if (len != T.len) return 0;
        for (int i = len - 1; i >= 0; i--)
            if (a[i] != T.a[i]) return 0;
        return 1;
    }

    BigInt operator+(const BigInt &T) const {
        BigInt ret = T;
        int maxlen = len > T.len ? len : T.len;   // 取长度最长的那个
        for (int i = 0; i < maxlen; i++) {
            ret.a[i] += a[i];
            if (ret.a[i] >= 10) {
                ret.a[i + 1]++;
                ret.a[i] -= 10;
            }
        }
        ret.len = ret.a[maxlen] > 0 ? maxlen + 1 : maxlen;
        return ret;
    }

    BigInt operator-(const BigInt &T) const {
        BigInt t1, t2;
        bool flag;
        if (*this > T) {   // 取得最大数并标记首位是否为负
            t1 = *this, t2 = T;
            flag = 0;
        } else {
            t1 = T, t2 = *this;
            flag = 1;
        }
        int maxlen = t1.len;
        for (int i = 0; i < maxlen; i++) {
            if (t1.a[i] < t2.a[i]) {   // 需要向前借位
                int j = i + 1;
                while (t1.a[j] == 0) j++;
                t1.a[j--]--;
                while (j > i) t1.a[j--] = 9;
                t1.a[i] += 10 - t2.a[i];
            } else
                t1.a[i] -= t2.a[i];
        }
        while (t1.a[maxlen - 1] == 0 && t1.len > 1) {   // 看看从最高位开始是否被借位变为0
            t1.len--;
            maxlen--;
        }
        if (flag) t1.a[maxlen - 1] = -t1.a[maxlen - 1];   // 处理首位的正负
        return t1;
    }

    BigInt operator*(const BigInt &T) const {
        BigInt ans;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < T.len; j++) {
                ans.a[i + j] += a[i] * T.a[j] % 10;
                ans.a[i + j + 1] += a[i] * T.a[j] / 10;
            }
        }
        for (int i = 0; i < len + T.len; i++) {
            ans.a[i + 1] += ans.a[i] / 10;
            ans.a[i] %= 10;
        }
        ans.len = len + T.len;
        while (ans.a[ans.len - 1] == 0 && ans.len > 1) ans.len--;
        return ans;
    }

    BigInt operator/(const int &b) const {
        BigInt ret;
        int down = 0;
        for (int i = len - 1; i >= 0; i--) {
            ret.a[i] = (a[i] + down * 10) / b;
            down = a[i] + down * 10 - ret.a[i] * b;
        }
        ret.len = len;
        while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
        return ret;
    }

    int operator%(const int &b) const {
        int ret = 0;
        for (int i = len - 1; i >= 0; i--) ret = (ret * 10 + a[i]) % b;
        return ret;
    }

    BigInt pow(int n) {   // 传入的n非负
        string one = "1";
        BigInt x = *this, ret(one);
        while (n) {
            if (n & 1) ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }

    void println() {
        for (int i = len - 1; i >= 0; i--) printf("%d", a[i]);
        puts("");
    }

    void print() {
        for (int i = len - 1; i >= 0; i--) printf("%d", a[i]);
    }
};

// 输入__int128整数
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

// 输出__int128整数
void write(__int128_t x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    __int128_t a, b;
    a = read();
    b = read();
    write(a % b);
    write(a & b);
    return 0;
}

// 9223372036854775807

// bool operator>(const BigInt &T) const {
//     if (len > T.len) return 1;
//     if (len < T.len) return 0;
//     int cur = len - 1;
//     while (a[cur] == T.a[cur] && cur >= 0) cur--;
//     if (cur >= 0 && a[cur] > T.a[cur])
//         return 1;
//     else
//         return 0;
// }

// bool operator<(const BigInt &T) const {
//     if (len < T.len) return 1;
//     if (len > T.len) return 0;
//     int cur = len - 1;
//     while (a[cur] == T.a[cur] && cur >= 0) cur--;
//     if (cur >= 0 && a[cur] < T.a[cur])
//         return 1;
//     else
//         return 0;
// }

// bool operator==(const BigInt &T) const {
//     if (len != T.len) return 0;
//     for (int i = len - 1; i >= 0; i--)
//         if (a[i] != T.a[i]) return 0;
//     return 1;
// }

// BigInt operator+(const BigInt &T) const {
//     BigInt ret = T;
//     int maxlen = len > T.len ? len : T.len;   // 取长度最长的那个
//     for (int i = 0; i < maxlen; i++) {
//         ret.a[i] += a[i];
//         if (ret.a[i] >= 10) {
//             ret.a[i + 1]++;
//             ret.a[i] -= 10;
//         }
//     }
//     ret.len = ret.a[maxlen] > 0 ? maxlen + 1 : maxlen;
//     return ret;
// }

// BigInt operator-(const BigInt &T) const {
//     BigInt t1, t2;
//     bool flag;
//     if (*this > T) {   // 取得最大数并标记首位是否为负
//         t1 = *this, t2 = T;
//         flag = 0;
//     } else {
//         t1 = T, t2 = *this;
//         flag = 1;
//     }
//     int maxlen = t1.len;
//     for (int i = 0; i < maxlen; i++) {
//         if (t1.a[i] < t2.a[i]) {   // 需要向前借位
//             int j = i + 1;
//             while (t1.a[j] == 0) j++;
//             t1.a[j--]--;
//             while (j > i) t1.a[j--] = 9;
//             t1.a[i] += 10 - t2.a[i];
//         } else
//             t1.a[i] -= t2.a[i];
//     }
//     while (t1.a[maxlen - 1] == 0 && t1.len > 1) {   // 看看从最高位开始是否被借位变为0
//         t1.len--;
//         maxlen--;
//     }
//     if (flag) t1.a[maxlen - 1] = -t1.a[maxlen - 1];   // 处理首位的正负
//     return t1;
// }

// BigInt operator*(const BigInt &T) const {
//     BigInt ans;
//     for (int i = 0; i < len; i++) {
//         for (int j = 0; j < T.len; j++) {
//             ans.a[i + j] += a[i] * T.a[j] % 10;
//             ans.a[i + j + 1] += a[i] * T.a[j] / 10;
//         }
//     }
//     for (int i = 0; i < len + T.len; i++) {
//         ans.a[i + 1] += ans.a[i] / 10;
//         ans.a[i] %= 10;
//     }
//     ans.len = len + T.len;
//     while (ans.a[ans.len - 1] == 0 && ans.len > 1) ans.len--;
//     return ans;
// }

// BigInt operator/(const int &b) const {
//     BigInt ret;
//     int down = 0;
//     for (int i = len - 1; i >= 0; i--) {
//         ret.a[i] = (a[i] + down * 10) / b;
//         down = a[i] + down * 10 - ret.a[i] * b;
//     }
//     ret.len = len;
//     while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
//     return ret;
// }

// int operator%(const int &b) const {
//     int ret = 0;
//     for (int i = len - 1; i >= 0; i--) ret = (ret * 10 + a[i]) % b;
//     return ret;
// }

// BigInt pow(int n) {   // 传入的n非负
//     string one = "1";
//     BigInt x = *this, ret(one);
//     while (n) {
//         if (n & 1) ret = ret * x;
//         x = x * x;
//         n >>= 1;
//     }
//     return ret;
// }