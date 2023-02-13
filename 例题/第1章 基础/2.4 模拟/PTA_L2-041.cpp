#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 2e5 + 10;

int N, M, K;   // N: 推送器上松针的数目；M: 小盒子的容量；K：松枝的容量
vector<int> machine;   // 推送器
vector<int> box;       // 小盒子
vector<int> s;         // 松枝数组

// 打印松枝
void print() {
    if (!s.size()) return;
    for (int i = 0; i < s.size(); i++) printf("%d%c", s[i], i == s.size() - 1 ? '\n' : ' ');
    s.clear();
}

// 是否能插入松枝
bool insertS(int x) {
    if (s.empty()) {
        s.push_back(x);
        return true;
    }
    if (s.back() >= x) {
        s.push_back(x);
        return true;
    }
    return false;
}

// 是否能插入盒子
bool insertBox(int x) {
    if (box.size() < M) {
        box.push_back(x);
        return true;
    }
    return false;
}

// 推送器为空后，只需要判断盒子
void onlyBoxOp() {
    print();
    while (!box.empty()) {
        while (!box.empty() && insertS(box.back())) {
            box.pop_back();
            if (s.size() == K) print();
        }
        print();
    }
}

void work() {
    // 无限的松枝
    while (1) {
        // 推送器&盒子均为空，结束程序
        if (box.empty() && machine.empty()) break;
        if (!box.empty() && insertS(box.back())) {   // 盒子不为空且可以从盒子中成功插入
            box.pop_back();
            if (s.size() == K) {
                print();
                continue;
            }
        } else {
            if (machine.empty()) {
                onlyBoxOp();
                break;
            }
            if (insertS(machine.back())) {
                machine.pop_back();
                if (s.size() == K) {
                    print();
                    continue;
                }
            } else {
                if (insertBox(machine.back()))
                    machine.pop_back();
                else
                    print();
            }
        }
    }
    print();
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1, x; i <= N; i++) {
        scanf("%d", &x);
        machine.push_back(x);
    }
    reverse(machine.begin(), machine.end());
    work();
    return 0;
}
