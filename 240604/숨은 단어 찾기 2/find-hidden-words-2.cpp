#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n, int m) {
    return (0<=x && 0<=y && x<n && y<m);
}

int main() {
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
    int n,m;
    cin >> n >> m;
    vector<char> row(m,'\0');
    vector<vector<char>> matrix(n, row);
    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) cin >> matrix[i][p];
    }
    int LEE_num = 0;
    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) {
            if(matrix[i][p] == 'L') {
                for(int q=0; q<8; q++) {
                    if(in_range(i+(2*dx[q]), p+(2*dy[q]), n, m)) {
                        if(matrix[i+dx[q]][p+dy[q]] == 'E' && matrix[i+(2*dx[q])][p+(2*dy[q])] == 'E') LEE_num++;
                    }
                }
            }
        }
    }
    cout << LEE_num;
    return 0;
}