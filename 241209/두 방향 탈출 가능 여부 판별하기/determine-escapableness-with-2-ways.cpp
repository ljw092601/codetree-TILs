#include <iostream>
#include <vector>
using namespace std;

int dx[2] = {1,0};
int dy[2] = {0,1};
bool finish = false;

bool in_range(int x, int y, vector<vector<int>>& m) {
    return 0 <= x && x < m.size() && 0 <= y && y < m[0].size();
}

bool canGo(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& v) {
    return in_range(x,y,m) && m[x][y] == 1 && v[x][y] == false;
}

void search(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& v) {
    if(x == m.size()-1 && y == m[0].size()-1) finish = true;
    for(int i=0; i<2; i++) {
        if (canGo(x+dx[i], y+dy[i], m, v)) {
            v[x+dx[i]][y+dy[i]] = true;
            search(x+dx[i], y+dy[i], m, v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) {
        vector<int> v(m);
        for(int p=0; p<m; p++) {
            cin >> v[p];
        }
        maze.push_back(v);
    }
    
    visited[0][0] = true;
    search(0,0, maze, visited);
    cout << (finish ? 1 : 0);

    return 0;
}