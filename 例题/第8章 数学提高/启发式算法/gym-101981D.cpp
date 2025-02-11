#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-14;
 
struct Tpoint {
  double x, y, z;
 };
  
 Tpoint pt[200000], outer[4], res;
 double radius;
 int n, nouter;
  
 inline double dist(Tpoint p1, Tpoint p2) {
     double dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
     return (dx * dx + dy * dy + dz * dz);
 }
  
 inline double dot(Tpoint p1, Tpoint p2) {
     return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
 }
  
 void ball() {
     Tpoint q[3];
     double m[3][3], sol[3], L[3], det;
     int i, j;
     res.x = res.y = res.z = radius = 0;
     switch (nouter) {
         case 1 :res = outer[0];
             break;
         case 2 :res.x = (outer[0].x + outer[1].x) / 2;
             res.y = (outer[0].y + outer[1].y) / 2;
             res.z = (outer[0].z + outer[1].z) / 2;
             radius = dist(res, outer[0]);
             break;
         case 3 :
             for (int i = 0; i < 2; i++) {
                 q[i].x = outer[i + 1].x - outer[0].x;
                 q[i].y = outer[i + 1].y - outer[0].y;
                 q[i].z = outer[i + 1].z - outer[0].z;
             }
             for (int i = 0; i < 2; i++)
                 for (int j = 0; j < 2; j++)
                     m[i][j] = dot(q[i], q[j]) * 2;
             for (int i = 0; i < 2; i++) sol[i] = dot(q[i], q[i]);
             if (fabs(det = m[0][0] * m[1][1] - m[0][1] * m[1][0]) < eps)
                 return;
             L[0] = (sol[0] * m[1][1] - sol[1] * m[0][1]) / det;
             L[1] = (sol[1] * m[0][0] - sol[0] * m[1][0]) / det;
             res.x = outer[0].x + q[0].x * L[0] + q[1].x * L[1];
             res.y = outer[0].y + q[0].y * L[0] + q[1].y * L[1];
             res.z = outer[0].z + q[0].z * L[0] + q[1].z * L[1];
             radius = dist(res, outer[0]);
             break;
         case 4 :
             for (int i = 0; i < 3; i++) {
                 q[i].x = outer[i + 1].x - outer[0].x;
                 q[i].y = outer[i + 1].y - outer[0].y;
                 q[i].z = outer[i + 1].z - outer[0].z;
                 sol[i] = dot(q[i], q[i]);
             }
             for (int i = 0; i < 3; i++)
                 for (int j = 0; j < 3; j++) m[i][j] = dot(q[i], q[j]) * 2;
             det = m[0][0] * m[1][1] * m[2][2]
                 + m[0][1] * m[1][2] * m[2][0]
                 + m[0][2] * m[2][1] * m[1][0]
                 - m[0][2] * m[1][1] * m[2][0]
                 - m[0][1] * m[1][0] * m[2][2]
                 - m[0][0] * m[1][2] * m[2][1];
             if (fabs(det) < eps) return;
             for (int j = 0; j < 3; j++) {
                 for (int i = 0; i < 3; i++) m[i][j] = sol[i];
                 L[j] = (m[0][0] * m[1][1] * m[2][2]
                     + m[0][1] * m[1][2] * m[2][0]
                     + m[0][2] * m[2][1] * m[1][0]
                     - m[0][2] * m[1][1] * m[2][0]
                     - m[0][1] * m[1][0] * m[2][2]
                     - m[0][0] * m[1][2] * m[2][1]
                 ) / det;
                 for (int i = 0; i < 3; i++) m[i][j] = dot(q[i], q[j]) * 2;
             }
             res = outer[0];
             for (int i = 0; i < 3; i++) {
                 res.x += q[i].x * L[i];
                 res.y += q[i].y * L[i];
                 res.z += q[i].z * L[i];
             }
             radius = dist(res, outer[0]);
     }
 }
  
 void minbool(int n) {
     ball();
     if (nouter < 4)
         for (int i = 0; i < n; i++)
             if (dist(res, pt[i]) - radius > eps) {
                 outer[nouter] = pt[i];
                ++nouter;
                minbool(i);
                --nouter;
                if (i > 0) {
                    Tpoint Tt = pt[i];
                    memmove(&pt[1], &pt[0], sizeof(Tpoint) * i);
                    pt[0] = Tt;
                }
            }
}
 
double smallest_bool() {    //返回最小覆盖球半径
    radius = -1;
    for (int i = 0; i < n; i++) {
        if (dist(res, pt[i]) - radius > eps) {
            nouter = 1;
            outer[0] = pt[i];
            minbool(i);
        }
    }
    return sqrt(radius);
}
 
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &pt[i].x, &pt[i].y, &pt[i].z);
    }
    printf("%.8lf\n", smallest_bool());
}
 
int main() {
    solve();
    return 0;
}