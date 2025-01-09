#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

bool is_pos(int x1, int y1, int x2, int y2) {
    for(int i=x1; i<=x2; i++) {
        for(int p=y1; p<=y2; p++) {
            if(grid[i][p] <= 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int max_size = 0;
    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) {
            for(int k=i; k<n; k++) {
                for(int l=p; l<m; l++) {
                    if(is_pos(i,p,k,l)) max_size = max(max_size, (k-i+1)*(l-p+1));
                }
            }
        }
    }

    cout << (max_size ? max_size : -1);

    return 0;
}
