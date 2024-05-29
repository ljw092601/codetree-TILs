#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n, int m) {
    return (0<=x && 0<=y && x<n && y<m);
}

int main() {
    int arr_x[4] = {0,1, 0,-1};
    int arr_y[4] = {1,0,-1, 0};
    int n, m;
    cin >> n >> m;
    vector<int> zero_vec(m, 0);
    vector<vector<int>> double_vec(n, zero_vec);
    int number = 1;
    int direction = 0;
    int x=0, y=0;
    while(true) {
        if (number == n*m) {
            double_vec[x][y] = number;
            break;
        }
        if (in_range(x+arr_x[direction%4], y+arr_y[direction%4], n, m) 
            && double_vec[x+arr_x[direction%4]][y+arr_y[direction%4]] == 0) {
            double_vec[x][y] = number;
            x += arr_x[direction%4];
            y += arr_y[direction%4];
            number++;
        }
        else {
            direction++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) {
            cout << double_vec[i][p] << " ";
        }
        cout << endl;
    }
    return 0;
}