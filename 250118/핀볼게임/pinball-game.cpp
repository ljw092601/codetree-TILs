#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int cal_time(int x, int y, int dir) {
    int time = 1;
    while(in_range(x, y)) {
        if(grid[x][y] == 1) dir = 3 - dir;
        else if (grid[x][y] == 2) {
            if(dir%2 == 0) dir++;
            else dir--;
        }
        x += dx[dir];
        y += dy[dir];
        time++;
    }
    return time;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    int max_time = 0;
    for(int i=0; i<n; i++) {
        max_time = max(max_time, cal_time(0,i,0));
        max_time = max(max_time, cal_time(i,0,1));
        max_time = max(max_time, cal_time(n-1,i,2));
        max_time = max(max_time, cal_time(i,n-1,3));
    }

    cout << max_time;

    return 0;
}
