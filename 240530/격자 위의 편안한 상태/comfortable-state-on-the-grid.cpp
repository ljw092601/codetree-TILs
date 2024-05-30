#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n) {
    return (0<=x && 0<=y && x<n && y<n);
}

int main() {
    int arr_x[4] = {1,0,-1,0};
    int arr_y[4] = {0,1,0,-1};
    int n, m;
    cin >> n >> m;
    vector<int> t_vec(n, 0);
    vector<vector<int>> d_vec(n, t_vec);
    while(m--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        d_vec[x][y] = 1;
        int tile = 0;
        for (int i=0; i<4; i++) {
            if(in_range(x+arr_x[i], y+arr_y[i], n)) {
                if(d_vec[x+arr_x[i]][y+arr_y[i]] == 1) tile++;
            }
        }
        if (tile == 3) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}