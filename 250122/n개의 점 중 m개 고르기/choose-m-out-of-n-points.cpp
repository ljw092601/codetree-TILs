#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
int x[20], y[20];
int selected[20];
int min_dist = INT_MAX;

int cal_dist_square(int idx1, int idx2) {
    return (x[idx1] - x[idx2]) * (x[idx1] - x[idx2]) + (y[idx1] - y[idx2]) * (y[idx1] - y[idx2]);
}

void pick_2point() {
    int max_dist = 0;
    for(int i=0; i<n-1; i++) {
        for(int p=i+1; p<n; p++) {
            if(selected[i] && selected[p]) max_dist = max(max_dist, cal_dist_square(i, p));
        }
    }
    min_dist = min(min_dist, max_dist);
}

void simulation(int t, int q) {
    if(q == m) {
        pick_2point();
        return;
    }
    if(t == n) return;
    selected[t] = 1;
    simulation(t+1, q+1);
    selected[t] = 0;
    simulation(t+1, q);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    simulation(0,0);

    cout << min_dist;

    return 0;
}
