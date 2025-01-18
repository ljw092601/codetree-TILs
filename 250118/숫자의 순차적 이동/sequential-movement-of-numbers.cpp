#include <iostream>

using namespace std;

int n, m;
int grid[20][20];
int dx[8] = {1,1,1,-1,-1,-1,0,0};
int dy[8] = {1,0,-1,1,0,-1,1,-1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

void swap(int x, int y) {
    int max = 0;
    int max_i;
    for(int i=0; i<8; i++) {
        if(in_range(x + dx[i], y + dy[i])) {
            if(max < grid[x + dx[i]][y + dy[i]]) {
                max = grid[x + dx[i]][y + dy[i]];
                max_i = i;
            }
        }
    }
    grid[x + dx[max_i]][y + dy[max_i]] = grid[x][y];
    grid[x][y] = max;
}

void move(int find) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == find) {
                swap(i, j);
                return;
            }
        }
    }
}

void turn() {
    for(int i = 1; i <= n*n; i++) {
        move(i);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<m; i++) turn();

    print();

    return 0;
}
