#include <iostream>

using namespace std;

int N;
int x, y;
int dir = 0;
char grid[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool in_range(int a, int b) {
    return 0 < a && a <= N && 0 < b && b <= N;
}

bool is_wall(int a, int b) {
    return grid[a+1][b] == '#';
}

void turn_L() {
    if(dir == 0) dir = 3;
    else dir--;
}

void turn_R() {
    if(dir == 3) dir = 0;
    else dir++;
}

bool cant_go() {
    return grid[x + dx[dir]][y + dy[dir]] == '#';
}

int cal_time() {
    bool right_wall = true;
    int time = 0;
    for(int g=0; g<N*N; g++) {
        if(!in_range(x,y)) return time;
        if(cant_go()) {
            turn_L();
        }
        x += dx[dir];
        y += dy[dir];
        if(right_wall && !is_wall(x, y)) {
            turn_R();
        }
        time++;
    }
    return -1;
}

int main() {
    cin >> N;
    cin >> x >> y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    cout << cal_time();

    return 0;
}
