#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coin {
    int num;
    int x;
    int y;
};

int N;
char grid[20][20];
vector<Coin> coins;
int selected[10];
int now_x;
int now_y;
int min_dist = 400;

int dist(int x2, int y2) {
    int dist = abs(x2 - now_x) + abs(y2 - now_y);
    now_x = x2;
    now_y = y2;
    return dist;
}

void cal_dist() {
    int st_x, st_y, ed_x, ed_y;
    for(int i=0; i<N; i++) {
        for(int p=0; p<N; p++) {
            if(grid[i][p] == 'S') {
                st_x = i;
                st_y = p;
            }
            if(grid[i][p] == 'E') {
                ed_x = i;
                ed_y = p;
            }
        }
    }
    now_x = st_x;
    now_y = st_y;
    int dist_sum = 0;
    for(int i=0; i<coins.size(); i++) {
        if(selected[i]) dist_sum += dist(coins[i].x, coins[i].y);
    }
    dist_sum += dist(ed_x, ed_y);
    min_dist = min(min_dist, dist_sum);
}

void simulation(int t, int q) {
    if(q == 3) {
        cal_dist();
        return;
    }
    if(t == coins.size()) return;
    selected[t] = 1;
    simulation(t+1, q+1);
    selected[t] = 0;
    simulation(t+1, q);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if('1' <= grid[i][j] && grid[i][j] <= '9') {
                coins.emplace_back(Coin{(int)grid[i][j] - '0', i, j});
            }
        }
    }

    sort(coins.begin(), coins.end(), [](Coin a, Coin b) {return a.num < b.num;});
    
    if(coins.size() < 3) cout << -1;
    else {
        simulation(0,0);
        cout << min_dist;
    }

    return 0;
}
