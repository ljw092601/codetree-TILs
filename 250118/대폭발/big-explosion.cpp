#include <iostream>
#include <cmath>
using namespace std;

int n, m, r, c;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool is_boom[101][101];
bool is_boom2[101][101];

bool in_range(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

void make_booms(int x, int y, int t) {
    int dist = pow(2,t-1);
    for(int i=0; i<4; i++) {
        if(in_range(x+dx[i]*dist, y+dy[i]*dist)) is_boom2[x+dx[i]*dist][y+dy[i]*dist] = true;
    }
}

int boom_num() {
    int num = 0;
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            if(is_boom[i][p]) num++;
        }
    }
    return num;
}

void boom_copy() {
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            is_boom[i][p] = is_boom2[i][p];
        }
    }
}

int main() {
    cin >> n >> m >> r >> c;
    is_boom[r][c] = true;
    is_boom2[r][c] = true;

    for(int t=1; t<=m; t++) {
        for(int i=1; i<=n; i++) {
            for(int p=1; p<=n; p++) {
                if(is_boom[i][p]) make_booms(i,p,t);
            }
        }
        boom_copy();
    }

    // for(int i=1; i<=n; i++) {
    //     for(int p=1; p<=n; p++) {
    //         if(is_boom[i][p]) cout << 1 << ' ';
    //         else cout << 0 << ' ';
    //     }
    //     cout << endl;
    // }

    cout << boom_num();

    return 0;
}
