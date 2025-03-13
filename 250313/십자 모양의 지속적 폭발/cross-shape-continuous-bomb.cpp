#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

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
    cout << endl;
}

void gravity() {
    for(int i=0; i<n; i++) {
        int temp[100] = {0,};
        int temp_idx = 0;
        for(int p=n-1; p>=0; p--) {
            if(grid[p][i]) {
                temp[temp_idx] = grid[p][i];
                temp_idx++;
            }
        }
        temp_idx = 0;
        for(int p=n-1; p>=0; p--) {
            grid[p][i] = temp[temp_idx];
            temp_idx++;
        }
    }
}

void boom(int x, int y) {
    int boom_size = grid[x][y];
    for(int i=0; i<4; i++) {
        for(int p=0; p<boom_size; p++) {
            if(in_range(x + dx[i]*p, y + dy[i]*p)) {
                grid[x + dx[i]*p][y + dy[i]*p] = 0;
            }
        }
    }
    gravity();
}

void pick_boom(int c) {
    c--;
    for(int i=0; i<n; i++) {
        if(grid[i][c]) {
            boom(i, c);
            return;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        pick_boom(c);
    }

    print();

    return 0;
}
