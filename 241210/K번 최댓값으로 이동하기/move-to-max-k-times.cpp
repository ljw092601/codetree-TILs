#include <iostream>
#include <queue>
using namespace std;

int matrix[100][100];
int visited[100][100] = {false};
int n;
int cur_num;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Point{
    int x;
    int y;
};

void visited_clear() {
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            visited[i][p] = false;
        }
    }
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool can_go(int x, int y) {
    return in_range(x,y) && matrix[x][y] < cur_num && visited[x][y] == false;
}

Point BFS(int a, int b) {
    cur_num = matrix[a][b];
    queue<Point> qu;
    qu.push(Point{a,b});
    visited_clear();
    visited[a][b] = true;
    int max_val = 0;
    int max_x = a;
    int max_y = b;

    while(!qu.empty()) {
        Point out = qu.front();
        qu.pop();
        int x = out.x;
        int y = out.y;
        //cout << x << " " << y << endl;
        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (can_go(new_x, new_y)) {
                visited[new_x][new_y] = true;
                qu.push(Point{new_x, new_y});
                if (matrix[new_x][new_y] > max_val) {
                    max_val = matrix[new_x][new_y];
                    max_x = new_x;
                    max_y = new_y;
                }
                else if(matrix[new_x][new_y] == max_val) {
                    if (max_x > new_x) {
                        max_x = new_x;
                        max_y = new_y;
                    }
                    else if (max_x == new_x) {
                        if (max_y > new_y) {
                            max_x = new_x;
                            max_y = new_y;
                        }
                    }
                }
            }
        }
    }
    return Point{max_x, max_y};
}

int main() {
    int k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            cin >> matrix[i][p];
        }
    }

    int x, y;
    cin >> x >> y;
    Point cur = {x-1,y-1};
    while(k--) {
        Point next = BFS(cur.x, cur.y);
        //cout << "******************" << endl;
        if(cur.x == next.x && cur.y == next.y) break;
        cur = next;
    }
    cout << cur.x+1 << " " << cur.y+1;
    return 0;
}