#include<iostream>
#include <cmath>

using namespace std;
 
int n, m;
 
const double lorry = (sqrt(5.0) + 1.0) / 2.0;
 
int main() {
    cin >> n >> m;
    if(n < m) swap(n, m);
    int a = n - m;
    if(m == int(lorry * (double)a))
        cout << 0 << endl;
    else
        cout << 1 << endl;
}
