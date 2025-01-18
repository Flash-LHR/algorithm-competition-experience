#include<iostream>
using namespace std;


void floyd_3d(){
        for (int k = 1; k <= n; k++){
        for (int x = 1; x <= n; x++){
        for (y = 1; y <= n; y++){
            f[k][x][y] = min(f[k - 1][x][y], f[k - 1][x][k] + f[k - 1][k][y]);
        }
    }
    // 三维数组
}

void floyd_2d(){
    for (k = 1; k <= n; k++){
        for (x = 1; x <= n; x++){
            for (y = 1; y <= n; y++){
                f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
            }
        }
    }
    // 二维数组
}

int main(){
    return 0;
}
