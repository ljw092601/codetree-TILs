#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n, int m) {
    return (0<=x && 0<=y && x<n && y<m);
}

void draw_matrix(vector<vector<int>>& vec, int n) {
    int arr_x[4] = {0,-1, 0,1};
    int arr_y[4] = {1,0,-1, 0};
    int number = 1;
    int direction = 0;
    int repeat = 1;
    int x=n/2, y=n/2;
    while(true) {
        for (int p=0; p<2; p++) {
            for (int i=0; i<repeat; i++) {
                if (number == n*n) {
                    vec[x][y] = number;
                    return;
                }
                if (in_range(x+arr_x[direction%4], y+arr_y[direction%4], n, n)) {
                    vec[x][y] = number;
                    x += arr_x[direction%4];
                    y += arr_y[direction%4];
                    number++;
                }
            }
            direction++;
        }
        repeat++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> zero_vec(n, 0);
    vector<vector<int>> double_vec(n, zero_vec);
    draw_matrix(double_vec, n);

    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            cout << double_vec[i][p] << " ";
        }
        cout << endl;
    }
    return 0;
}