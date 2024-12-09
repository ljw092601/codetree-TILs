#include <iostream>
using namespace std;

int n;
int cur_n;
int block_size = 0;
int matrix[100][100] = {0};
bool visited[100][100] = {false};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool canGo(int x, int y) {
    return in_range(x,y) && visited[x][y] == false && matrix[x][y] == cur_n;
}

void search(int x, int y) {  
    visited[x][y] = true;
    block_size++;
    for(int i=0; i<4; i++) {
        if (canGo(x+dx[i], y+dy[i])) {
            search(x+dx[i], y+dy[i]);
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            cin >> matrix[i][p];
        }
    }
    int max_block = 0;
    int boom = 0;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            if(visited[i][p] == false) {
                block_size = 0;
                cur_n = matrix[i][p];
                search(i, p);
                if(block_size >= 4) boom++;
                if(max_block < block_size) max_block = block_size;
            }
        }
    }
    cout << boom << " " << max_block;
    return 0;
}