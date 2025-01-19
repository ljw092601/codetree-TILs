#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct Marble {
    int num = 0;
    int weight = 0;
    int dir = -1;
};

int n, t;
vector<vector<vector<Marble>>> grid(50, vector<vector<Marble>>(50));
vector<vector<vector<Marble>>> temp_grid(50, vector<vector<Marble>>(50));
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool in_range(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

void print() {
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            cout << grid[i][p].size() << ' ';
        }
        cout << endl;
    }
}

int dir_translate(char d) {
    if(d == 'D') return 0;
    if(d == 'U') return 1;
    if(d == 'R') return 2;
    if(d == 'L') return 3;
}

int count_marble() {
    int count = 0;
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            count += grid[i][p].size();
        }
    }
    return count;
}

int max_weight() {
    int max_w = 0;
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            if(!grid[i][p].empty()) {
                for(Marble m : grid[i][p]) max_w = max(max_w, m.weight);
            }
        }
    }
    return max_w;
}

void clean() {
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            temp_grid[i][p].clear();
        }
    }
}

tuple<int, int> find_new_xy(int x, int y, Marble& m) {
    if(m.dir == 0 && x == n) m.dir = 1;
    else if(m.dir == 1 && x == 1) m.dir = 0;
    else if(m.dir == 2 && y == n) m.dir = 3;
    else if(m.dir == 3 && y == 1) m.dir = 2;
    else {
        x += dx[m.dir];
        y += dy[m.dir];
    }
    
    tuple<int, int> new_xy(x, y);
    return new_xy;
}

void move(int x, int y) {
    for(Marble& m : grid[x][y]) {
        int new_x, new_y;
        tie(new_x, new_y) = find_new_xy(x, y, m);
        temp_grid[new_x][new_y].emplace_back(m);
    }
}

void copy() {
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            grid[i][p].clear();
        }
    }
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            for(Marble m : temp_grid[i][p]) {
                grid[i][p].emplace_back(m);
            }
        }
    }
}

void collapse() {
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            if(grid[i][p].size() >= 2) {
                Marble sum_m;
                for(Marble m : grid[i][p]) {
                    sum_m.weight += m.weight;
                    if (sum_m.num < m.num) {
                        sum_m.num = m.num;
                        sum_m.dir = m.dir;
                    }
                }
                grid[i][p].clear();
                grid[i][p].emplace_back(sum_m);
            }
        }
    }
}

void all_move() {
    clean();
    for(int i=1; i<=n; i++) {
        for(int p=1; p<=n; p++) {
            if(!grid[i][p].empty()) {
                move(i,p);
            }
        }
    }
    copy();
    // print();
    collapse();
}

int main() {
    int m;
    cin >> n >> m >> t;

    for (int i = 1; i <= m; i++) {
        Marble marble;
        int x, y;
        char direction;
        cin >> x >> y >> direction >> marble.weight;
        marble.dir = dir_translate(direction);
        marble.num = i;
        grid[x][y].emplace_back(marble);
    }
    // print();
    // cout << endl;

    while(t--) {
        all_move();
    }

    cout << count_marble() << ' ' << max_weight();

    return 0;
}
