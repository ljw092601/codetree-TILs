#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool in_range(int x, int y, int n) {
    return (0<=x && 0<=y && x<n && y<n);
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> d_vec;
    string command;
    cin >> command;
    for (int i=0; i<n; i++) {
        vector<int> temp;
        for (int p=0; p<n; p++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        d_vec.push_back(temp);
    }
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    int dir = 100000;
    int x = n/2, y = n/2;
    int sum = d_vec[x][y];
    for (char c : command) {
        if(c == 'R') {
            dir++;
        }
        else if (c == 'L') {
            dir--;
        }
        else if (c == 'F') {
            if(in_range(x+dx[dir%4], y+dy[dir%4], n)) {
                x += dx[dir%4];
                y += dy[dir%4];
                sum += d_vec[x][y];
            }
        }
    }
    cout << sum;
    return 0;
}