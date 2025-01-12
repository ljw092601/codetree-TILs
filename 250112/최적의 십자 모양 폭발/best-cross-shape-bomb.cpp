#include <iostream>
#include <vector>
using namespace std;

int n;
int save_grid[50][50];
int grid[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = save_grid[i][j];
        }
    }
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int cnt_pair() {
    int pair = 0;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            if(grid[i][p]) {
                for(int j=0; j<4; j++) {
                    if(in_range(i + dx[j], p + dy[j]) && grid[i][p] == grid[i+dx[j]][p+dy[j]]) pair++; 
                }
            }
        }
    }
    return pair / 2;
}

void gravity() {
    for(int i=0; i<n; i++) {
        vector<int> temp (n, 0);
        int idx = 0;
        for(int p=n-1; p>=0; p--) {
            if(grid[p][i]) {
                temp[idx] = grid[p][i];
                idx++;
            }
        }
        idx = 0;
        for(int p=n-1; p>=0; p--) {
            grid[p][i] = temp[idx];
            idx++;
        }
    }
}

void boom(int x, int y) {
    int size = grid[x][y];

    for(int i=0; i<4; i++) {
        for(int p=0; p<size; p++) {
            if(in_range(x + dx[i] * p, y + dy[i] * p)) grid[x + dx[i] * p][y + dy[i] * p] = 0;
        }
    }

    gravity();
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> save_grid[i][j];
        }
    }

    int max_pair = 0;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            init();
            boom(i, p);
            max_pair = max(max_pair, cnt_pair());
        }
    }

    cout << max_pair;

    return 0;
}
