#include <vector>
vector<int> a; //  相当于一个长度动态变化的int数组
vector<int> b[233]; //  相当于第一维长233，第二维长度动态变化的int数组
vector<int> c(233, 0); //  相当于一个长度动态变化的int数组，初始长度为233，初始元素均为0
struct rec{...};
vector<rec> c; //  自定义的结构体类型也可以保存在vector中

vector<int>::iterator it;

for (size_t i = 0; i < a.size(); i++)
    cout << a[i] << endl;
for (vector<int>::iterator it = a.begin(), it != a.end(); it++)
    cout << *it << endl;
for (const auto& x: a)
    cout << x << endl;