queue<int> q;
struct rec{...}; queue<rec> q;
priority_queue<int> q;
/*
pair<>: C++内置的二元组，尖括号中分别指定二元组的第一元、第二元的类型。
可以用make_pair函数创建二元组，用成员变量first访问第一元，second访问第二元。
在比较大小时，以第一元作为第一关键字，第二元作为第二关键字。
*/
priority_queue<pair<int, int>> q;