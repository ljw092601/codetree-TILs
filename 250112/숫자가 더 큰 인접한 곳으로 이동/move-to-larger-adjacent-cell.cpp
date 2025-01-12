#include <iostream>

using namespace std;

int n;
int r, c;
int a[100][100];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool in_range(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    bool can_go = true;

    while(can_go) {
        can_go = false;
        cout << a[r][c] << ' ';
        for(int i=0; i<4; i++) {
            int new_x = r+dx[i];
            int new_y = c+dy[i];
            if(in_range(new_x, new_y), a[r][c] < a[new_x][new_y]) {
                can_go = true;
                r = new_x;
                c = new_y;
                break;
            }
        }
    }

    return 0;
}
