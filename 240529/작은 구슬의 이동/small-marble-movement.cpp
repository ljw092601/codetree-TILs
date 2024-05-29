#include <iostream>
using namespace std;

int direction(char d) {
    if (d == 'R') return 1;
    if (d == 'L') return 2;
    if (d == 'U') return 0;
    if (d == 'D') return 3;
}

bool in_range(int x, int y, int n) {
    return (0<x && 0<y && x<=n && y<=n);
}

int main() {
    int arr_x[4] = {1,0, 0, -1};
    int arr_y[4] = {0,1,-1, 0};
    int n, t;
    cin >> n >> t;
    int st_x, st_y;
    char dir;
    cin >> st_x >> st_y >> dir;
    int dir_n = direction(dir);
    while(t--) {
        if (in_range(st_x + arr_x[dir_n], st_y + arr_y[dir_n], n)) {
            st_x += arr_x[dir_n];
            st_y += arr_y[dir_n];
        }
        else dir_n = 3 - dir_n;
    }
    cout << st_x << " " << st_y;
    return 0;
}