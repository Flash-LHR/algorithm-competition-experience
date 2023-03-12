#include <iostream>

using namespace std;

int main() {
    int N, n, m;
    cin >> N;
    while (N--) {
        cin >> n >> m;
        if (n % (m + 1) == 0) {
            cout << "second" << endl;
        } else cout << "first" << endl;
    }
    return 0;
}
