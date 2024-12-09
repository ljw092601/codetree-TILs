#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool in_range(int x, int y, vector<vector<int>>& m) {
    return 0 <= x && x < m.size() && 0 <= y && y < m[0].size();
}

bool canGo(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& v) {
    return in_range(x,y,m) && m[x][y] == 1 && v[x][y] == false;
}

void search(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& v) {
    v[x][y] = true;
    for(int i=0; i<4; i++) {
        if (canGo(x+dx[i], y+dy[i], m, v)) {
            search(x+dx[i], y+dy[i], m, v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> houses;
    int max_h = 0;
    for(int i=0; i<n; i++) {
        vector<int> v(m);
        for(int p=0; p<m; p++) {
            cin >> v[p];
            if (v[p] > max_h) max_h = v[p];
        }
        houses.push_back(v);
    }

    int max_vilige = 0;
    int max_k = 1;

    for(int k=1; k<= max_h; k++) {
        vector<vector<int>> maze;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            vector<int> v(m);
            for(int p=0; p<m; p++) {
                if(houses[i][p] <= k) v[p] = 0;
                else v[p] = 1;
            }
            maze.push_back(v);
        }
        int vilige = 0;
        for(int i=0; i<n; i++) {
            for(int p=0; p<m; p++) {
                if(maze[i][p] == 1 && visited[i][p] == false) {
                    search(i, p, maze, visited);
                    vilige++;
                }
            }
        }
        if (max_vilige < vilige) {
            max_vilige = vilige;
            max_k = k;
        }
    }

    cout << max_k << " " << max_vilige << endl;


    return 0;
}