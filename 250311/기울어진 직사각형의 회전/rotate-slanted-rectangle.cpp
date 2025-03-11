#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;
int dx[4] = {-1,-1,1,1};
int dy[4] = {1,-1,-1,1};

void rotate_clockwise() {
    int temp = grid[r][c];

    while(m1--) {
        grid[r][c] = grid[r+dx[0]][c+dy[0]];
        r += dx[0];
        c += dy[0];
    }
    while(m2--) {
        grid[r][c] = grid[r+dx[1]][c+dy[1]];
        r += dx[1];
        c += dy[1];
    }
    while(m3--) {
        grid[r][c] = grid[r+dx[2]][c+dy[2]];
        r += dx[2];
        c += dy[2];
    }
    while(m4--) {
        grid[r][c] = grid[r+dx[3]][c+dy[3]];
        r += dx[3];
        c += dy[3];
    }
    grid[r-dx[3]][c-dy[3]] = temp;
}

void rotate_couterclockwise() {
    int temp = grid[r][c];

    while(m4--) {
        grid[r][c] = grid[r-dx[3]][c-dy[3]];
        r -= dx[3];
        c -= dy[3];
    }
    while(m3--) {
        grid[r][c] = grid[r-dx[2]][c-dy[2]];
        r -= dx[2];
        c -= dy[2];
    }
    while(m2--) {
        grid[r][c] = grid[r-dx[1]][c-dy[1]];
        r -= dx[1];
        c -= dy[1];
    }
    while(m1--) {
        grid[r][c] = grid[r-dx[0]][c-dy[0]];
        r -= dx[0];
        c -= dy[0];
    }
    grid[r+dx[0]][c+dy[0]] = temp;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r--;
    c--;

    if(dir) rotate_clockwise();
    else rotate_couterclockwise();

    print();

    return 0;
}