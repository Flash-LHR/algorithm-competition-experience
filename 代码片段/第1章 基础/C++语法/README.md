## 引用

```c++
int x = 1;
int &y = x;
y = 2;
printf("%d", x);   // 结果为：2
```

```c++
int a = 12, b = 7;
int *p1 = &a;               // 普通指针
int &r = a;                 // 引用
int *const p2 = &a;         // 顶层const指针
```

```c++
// 交换两个整数a,b的函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## 命名空间

```c++
namespace mynsp {
int cnt;
 
void set(int x) {
    cnt = x;
}
}
```

```c++
namespace mynsp1 {
namespace mynsp2 {
int cnt;
void set(int x) {
    cnt = x;
}
}
 
int cnt;
void set(int x) {
    cnt = x;
    mynsp2::set(x - 1);
}
}
 
int main() {
    mynsp1::set(10);
    // 输出：10 9
    std::cout << mynsp1::cnt << " " << mynsp1::mynsp2::cnt << std::endl;
    return 0;
}
```

## 结构体

```c++
// 结构体声明方式
struct strcut_name {
    type1 member1;   // 成员1
    type2 member2;   // 成员2
    type3 member3;   // 成员3
    ...
} object_name1;   // 结构体声明变量方式1
 
struct_name object_name2;   // 结构体声明变量方式2
 
// Books结构体示例
struct Books {
    int id;
    string name;
    string author;
    double price;
};
```

```c++
Books book1;   // 未初始化结构体变量
Books book2 = {1, "How to win ICPC", "tourist", 56.8};
Books book3 = {1, "How to win ICPC"};   // 仅仅初始化id和name两个成员
Books book3 = {1, 25.9};                // 报错
```

```c++
struct Books {
    int id;
    string name;
    string author;
    double price;
 
    // 手动声明默认构造函数
    Books() {}
 
    // 构造函数1
    Books(int id, string name, string author, double price) {
        this->id = id;
        this->name = name;
        this->author = author;
        this->price = price;
    }
 
    // 构造函数2
    Books(int id, string name, string author, double price)
        : id(id), name(name), author(author), price(price) {}
};
 
Books book;   // 若没有默认构造函数此语句报错
```

```c++
struct node {
    int x, y;
 
    // 成员函数结构体重载，定义在结构体内
    node operator+(const node &T) {
        return {this->x + T.x, this->y + T.y};
    }
};
 
// 非成员函数运算符重载，定义在结构体外
node operator+(const node &A, const node &B) {
    return {A.x + B.x, A.y + B.y};
}
```

```c++
struct node {
    int l, r;
 
    // 优先队列中的l较大者优先出队
    bool operator<(const node &T) const {
        return l < T.l;
    }
};
 
priority_queue<node> q;
```

## 函数模板

```c++
template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}
```

```c++
int a = 1, b = 2;
double c = 3.0, d = 4.0;
 
max(a, b);
max<double>(a, b);
```

## C++ 新特性

### 自动类型推导

```c++
auto a = 1, b = 2;
auto func = [&]() {
    return a * b;
};
auto c = func();
vector<vector<int>> nums;
auto iter = nums.begin();
```

### 初始化列表

```c++
struct node {
    int x, y, z;
};
 
vector<int> a{1, 2, 3, 4};
int nums[]{4, 3, 2, 1};
node x = {1, 1, 1};
double d{};     // 0.0
```

### for-each循环

```c++
vector<int> a{1, 2, 3, 4, 5};
for (auto x : a) {
    // ...
}
```

```c++
vector<int> a{1, 2, 3, 4, 5};
for (auto &x : a) {
    // ...
}
```

```c++
vector<pair<int, int>> nums{{1, 2}, {3, 4}, {5, 6}};
for (auto &[x, y] : nums) {
    // ...
}
```

### lambda表达式

```c++
int a = 1, b = 2;
auto func = [&, b]() { a = b; };
```

```c++
struct node {
    int l, r;
};
 
bool cmp(node &A, node &B) {
    return A.l < B.l;
}
 
int main() {
    vector<node> a{{2, 3}, {1, 2}, {0, 4}};
    vector<node> b{{2, 3}, {1, 2}, {0, 4}};
    sort(a.begin(), a.end(), [](node &A, node &B) {
        return A.l < B.l;
    });
    sort(b.begin(), b.end(), cmp);
    return 0;
}
```

### std::function

```c++
int main() {
    vector<vector<int>> graph;
    std::function<void(int, int)> dfs = [&](int fa, int u) {
        for (auto &v : graph[u]) {
            if (fa != v) {
                dfs(u, v);
            }
        }
    };
    return 0;
}
```

### 可变参数模板

```c++
template<typename... Values>
void func(Values... values)

func();
func(1);
func(1, 3.14);
func(1, 1e300, "abc");
```

```c++
template<typename T>
auto max(T t) {
    return t;
}
 
template<typename First, typename... Rest>
auto max(First first, Rest... rest) {
    const auto second = max(rest...);
    return first > second ? first : second;
}
 
std::cout << max(1, 2, 99, 3000) << std::endl;
```

