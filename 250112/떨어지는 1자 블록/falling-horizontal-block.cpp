#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int land_idx() {
    for(int i=0; i<n; i++) {
        for(int p=k-1; p<k-1+m; p++) {
            if(grid[i][p]) return i-1;
        }
    }
    return n-1;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int land = land_idx();

    for(int p=k-1; p<k-1+m; p++) {
        grid[land][p] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
