#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[100][100] = {0};
bool visited[100][100] = {false};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct P {
    int x;
    int y;
};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool canGo(int x, int y) {
    return in_range(x,y) && map[x][y] == 1 && visited[x][y] == false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) {
            cin >> map[i][p];
        }
    }
    queue<P> q;
    q.push(P{0,0});
    visited[0][0] = true;

    while(!q.empty()) {
        P out = q.front();
        q.pop();
        int x = out.x;
        int y = out.y;
        for(int i=0; i<4; i++) {
            if (canGo(x+dx[i], y+dy[i])) {
                visited[x+dx[i]][y+dy[i]] = true;
                q.push({x+dx[i], y+dy[i]});
            }
        }
    }

    cout << (visited[n-1][m-1] ? 1 : 0);

    return 0;
}