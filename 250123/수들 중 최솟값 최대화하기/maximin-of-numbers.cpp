#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[10][10];
int selected[10];
bool visited[10];
int max_num = 0;

void cal_min_num() {
    int min_n = 10000;
    for(int i=0; i<n; i++) {
        min_n = min(min_n, grid[i][selected[i]]);
    }
    max_num = max(max_num, min_n);
}

void simulation(int k) {
    if(k == n) {
        cal_min_num();
        return;
    }
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            selected[k] = i;
            visited[i] = true;
            simulation(k+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    simulation(0);

    cout << max_num;

    return 0;
}
