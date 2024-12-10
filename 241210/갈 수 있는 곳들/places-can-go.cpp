#include <iostream>
#include <queue>
using namespace std;

int matrix[100][100];
int visited[100][100] = {false};
int n;
int go_num = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Point{
    int x;
    int y;
};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool can_go(int x, int y) {
    return in_range(x,y) && matrix[x][y] == 0 && visited[x][y] == false;
}

void BFS(int x, int y) {
    queue<Point> qu;
    qu.push(Point{x,y});
    visited[x][y] = true;
    go_num++;
    while(!qu.empty()) {
        Point out = qu.front();
        qu.pop();
        int x = out.x;
        int y = out.y;
        for(int i=0; i<4; i++) {
            if (can_go(x+dx[i], y+dy[i])) {
                visited[x+dx[i]][y+dy[i]] = true;
                go_num++;
                qu.push(Point{x+dx[i], y+dy[i]});
            }
        }
    }
}

int main() {
    int k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            cin >> matrix[i][p];
        }
    }

    while(k--) {
        int x, y;
        cin >> x >> y;
        if (!visited[x-1][y-1]) BFS(x-1, y-1);
    }
    cout << go_num;
    return 0;
}