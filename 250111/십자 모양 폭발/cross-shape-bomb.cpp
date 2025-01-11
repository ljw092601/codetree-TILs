#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[200][200];
int r, c;

void gravity() {
    for(int i=0; i<n; i++) {
        vector<int> temp(n, 0);
        int idx = 0;
        for(int p=n-1; p >= 0 ; p--) {
            if(grid[p][i]) {
                temp[idx] = grid[p][i];
                idx++;
            }
        }
        for(int p=0; p<n; p++) {
            grid[p][i] = temp[n - p - 1];
        }
    }
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void boom (int x, int y) {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    int size = grid[x][y];

    for(int i=0; i<4; i++) {
        for(int p=0; p<size; p++) {
            if(in_range(x + dx[i] * p, y + dy[i] * p)) grid[x + dx[i] * p][y + dy[i] * p] = 0;
        }
    }

    gravity();
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    boom(r-1, c-1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
