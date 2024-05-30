#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool in_range(int x, int y, int n) {
    return (0<=x && 0<=y && x<n && y<n);
}

int start_dir(int st, int n) {
    if (0 < st && st <= n) return 0;
    if (n < st && st <= n*2) return 1;
    if (n*2 < st && st <= n*3) return 2;
    if (n*3 < st && st <= n*4) return 3;
}

pair<int,int> start_tile(int st, int n) {
    if (0 < st && st <= n) return make_pair(0,st-1);
    if (n < st && st <= n*2) return make_pair((st-n)-1,n-1);
    if (n*2 < st && st <= n*3) return make_pair(n-1,3*n-st);
    if (n*3 < st && st <= n*4) return make_pair(4*n-st, 0);
}

int change_r (int d) {
    if(d == 0) return 1;
    if(d == 1) return 0;
    if(d == 2) return 3;
    if(d == 3) return 2;
}

int main() {
    int arr_x[4] = {1,0,-1,0};
    int arr_y[4] = {0,-1,0,1};
    int n;
    cin >> n;
    vector<vector<char>> d_vec;
    for (int i=0; i<n; i++) {
        vector<char> t_vec;
        for (int p=0; p<n; p++) {
            char mirror;
            cin >> mirror;
            t_vec.push_back(mirror);
        }
        d_vec.push_back(t_vec);
    }
    int start;
    cin >> start;
    int dir = start_dir(start, n);
    pair<int, int> tile = start_tile(start, n);
    int x = tile.first, y = tile.second;
    int reflect = 0;
    while(in_range(x, y, n)) {
        reflect++;
        if(d_vec[x][y] == '/') {
            dir = change_r(dir);
            x += arr_x[dir];
            y += arr_y[dir];
        }
        else if (d_vec[x][y] == '\\') {
            dir = 3 - dir;
            x += arr_x[dir];
            y += arr_y[dir];
        }
        else break;
    }
    cout << reflect;
}