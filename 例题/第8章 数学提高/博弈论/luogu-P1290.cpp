#include <iostream>
 
using namespace std;
typedef long long ll;
 
int cal(int a, int b) {
    if (a < b) swap(a, b);
    int res = a % b;
    if (res == 0) return 1;
    if (a / b > 1) return 1;
    return cal(b, res) ^ 1;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (cal(a, b)) cout << "Stan wins" << "\n";
        else cout << "Ollie wins" << "\n";
    }
    return 0;
}
