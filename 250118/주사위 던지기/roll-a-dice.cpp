#include <iostream>

using namespace std;

int n, m;
int r, c;
int grid[101][101];
int dice[3] = {1,2,3};

bool in_range(char dir) {
    if (dir == 'L') return 0 < r && r <= n && 1 < c && c <= n;
    else if(dir == 'R') return 0 < r && r <= n && 0 < c && c <= n-1;
    else if(dir == 'U') return 1 < r && r <= n && 0 < c && c <= n;
    else if(dir == 'D') return 0 < r && r <= n-1 && 0 < c && c <= n;
    else return 0 < r && r <= n && 0 < c && c <= n;
    return false;
}

void roll_L() {
    if(in_range('L')) {
        int a = dice[0];
        int b = dice[2];
        dice[0] = b;
        dice[2] = 7 - a;
        c--;
        grid[r][c] = 7 - dice[0];
        //cout << 'L' << endl;
    }
}

void roll_R() {
    if(in_range('R')) {
        int a = dice[0];
        int b = dice[2];
        dice[0] = 7 - b;
        dice[2] = a;
        c++;
        grid[r][c] = 7 - dice[0];
        //cout << 'R' << endl;
    }
}

void roll_U() {
    if(in_range('U')) {
        int a = dice[0];
        int b = dice[1];
        dice[0] = b;
        dice[1] = 7 - a;
        r--;
        grid[r][c] = 7 - dice[0];
        //cout << 'U' << endl;
    }
}

void roll_D() {
    if(in_range('D')) {
        int a = dice[0];
        int b = dice[1];
        dice[0] = 7 - b;
        dice[1] = a;
        r++;
        grid[r][c] = 7 - dice[0];
        //cout << 'D' << endl;
    }
}

void print_sum() {
    int sum = 0;
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            sum += grid[i][p];
        }
    }
    cout << sum;
}

void print() {
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            cout << grid[i][p] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m >> r >> c;

    grid[r][c] = 6;

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        if (command == 'L') roll_L();
        else if(command == 'R') roll_R();
        else if(command == 'U') roll_U();
        else if(command == 'D') roll_D();
        else;
    }

    //print();
    print_sum();

    return 0;
}
