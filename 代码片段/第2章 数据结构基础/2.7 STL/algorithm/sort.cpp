int a[M + 5];
bool cmp(int a, int b) {return a > b;}
sort(a + 1, a + n + 1, cmp);

struct rec {int id, x, y;};
bool operator<(const rec& a, const rec& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
vector<rec> a;
sort(a.begin(), a.end());
