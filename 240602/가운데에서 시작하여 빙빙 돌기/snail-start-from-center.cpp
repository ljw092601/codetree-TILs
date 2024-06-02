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


101 100 99 98 97 96 95 94 93 92 
102 65  64 63 62 61 60 59 58 57 
103 66  37 36 35 34 33 32 31 56 
104 67  38 17 16 15 14 13 30 55 
105 68  39 18 5  4  3  12 29 54 
106 69  40 19 6  1  2  11 28 53 
107 70  41 20 7  8  9  10 27 52 
108 71  42 21 22 23 24 25 26 51 
109 72  43 44 45 46 47 48 49 50 
110 73  74 75 76 77 78 79 80 81