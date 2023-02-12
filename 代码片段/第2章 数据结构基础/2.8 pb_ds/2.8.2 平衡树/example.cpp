// Common Header Simple over C++11
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds ::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int> >,
                  __gnu_pbds::rb_tree_tag,
                  __gnu_pbds::tree_order_statistics_node_update>
    trr;

int main() {
    int cnt = 0;
    trr.insert(mp(1, cnt++));
    trr.insert(mp(5, cnt++));
    trr.insert(mp(4, cnt++));
    trr.insert(mp(3, cnt++));
    trr.insert(mp(2, cnt++));
    // 树上元素 {{1,0},{2,4},{3,3},{4,2},{5,1}}
    auto it = trr.lower_bound(mp(2, 0));
    trr.erase(it);
    // 树上元素 {{1,0},{3,3},{4,2},{5,1}}
    auto it2 = trr.find_by_order(1);
    cout << (*it2).first << endl;
    // 输出排名 0 1 2 3 中的排名 1 的元素的 first:1
    int pos = trr.order_of_key(*it2);
    cout << pos << endl;
    // 输出排名
    decltype(trr) newtr;
    trr.split(*it2, newtr);
    for (auto i = newtr.begin(); i != newtr.end(); ++i) {
        cout << (*i).first << ' ';
    }
    cout << endl;
    // {4,2},{5,1} 被放入新树
    trr.join(newtr);
    for (auto i = trr.begin(); i != trr.end(); ++i) {
        cout << (*i).first << ' ';
    }
    cout << endl;
    cout << newtr.size() << endl;
    // 将 newtr 树并入 trr 树，newtr 树被删除。
    return 0;
}
