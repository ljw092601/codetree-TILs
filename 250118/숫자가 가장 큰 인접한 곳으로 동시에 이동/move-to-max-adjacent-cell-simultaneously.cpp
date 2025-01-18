#include <iostream>

using namespace std;

int n, m, t;
int grid[21][21];
int marble[21][21];
int new_marble[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


bool in_range(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

void clean() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            new_marble[i][j] = 0;
        }
    }
}

void copy() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            marble[i][j] = new_marble[i][j];
        }
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << new_marble[i][j] << ' '; 
        }
        cout << endl;
    }
}

void move(int x, int y) {
    int max = 0;
    int max_i;
    for(int i=0; i<4; i++) {
        if(in_range(x + dx[i], y + dy[i])) {
            if(max <= grid[x + dx[i]][y + dy[i]]) {
                max = grid[x + dx[i]][y + dy[i]];
                max_i = i;
            }
        }
    }
    new_marble[x + dx[max_i]][y + dy[max_i]]++;
}

void move_all() {
    clean();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(marble[i][j]) move(i,j);
        }
    }
    copy();
    //print();
    //cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(marble[i][j] >= 2) marble[i][j] = 0;
        }
    }
}

int count_marble() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(marble[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int mx, my;
        cin >> mx >> my;
        marble[mx][my] = 1;
    }

    for (int i = 0; i < t; i++) {
        move_all();
    }

    cout << count_marble();

    return 0;
}
