#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int people = 0;

bool in_range(int x, int y, int n) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool canGo(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& v) {
    return in_range(x,y,m.size()) && m[x][y] == 1 && v[x][y] == false;
}

void search(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& v) {
    for(int i=0; i<4; i++) {
        if (canGo(x+dx[i], y+dy[i], m, v)) {
            v[x+dx[i]][y+dy[i]] = true;
            people++;
            search(x+dx[i], y+dy[i], m, v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maze;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(int i=0; i<n; i++) {
        vector<int> v(n);
        for(int p=0; p<n; p++) {
            cin >> v[p];
        }
        maze.push_back(v);
    }

    vector<int> people_vec;
    int vilige = 0;
    
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            if(maze[i][p] == 1 && visited[i][p] == false) {
                people = 0;
                search(i, p, maze, visited);
                people_vec.push_back(people);
                vilige++;
            }
        }
    }
    sort(people_vec.begin(), people_vec.end());
    cout << vilige << endl;
    for(int i : people_vec) cout << i << endl;

    return 0;
}