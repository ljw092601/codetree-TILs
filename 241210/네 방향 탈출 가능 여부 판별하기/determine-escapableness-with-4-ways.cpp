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

    bool escape = false;

    while(!q.empty()) {
        P out = q.front();
        q.pop();
        int x = out.x;
        int y = out.y;
        if(x == n-1 && y == m-1) {
            escape = true;
            break;
        }
        visited[x][y] = true;
        for(int i=0; i<4; i++) {
            if (canGo(x+dx[i], y+dy[i])) q.push({x+dx[i], y+dy[i]});
        }
    }

    cout << (escape ? 1 : 0);

    return 0;
}