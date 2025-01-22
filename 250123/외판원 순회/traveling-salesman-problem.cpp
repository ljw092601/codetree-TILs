#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int A[11][11];
int selected[11];
bool visited[11];
int min_dist = INT_MAX;

int a_to_b(int a, int b) {
    return A[a][b];
}

void cal_dist() {
    int dist = 0;
    dist += a_to_b(1, selected[0]);
    for(int i=0; i<n-1; i++) {
        dist += a_to_b(selected[i], selected[i+1]);
    }
    dist += a_to_b(selected[n-2], 1);
    min_dist = min(min_dist, dist);
}

void simulation(int k) {
    if(k == n-1) {
        cal_dist();
        return;
    }
    for(int i=2; i<=n; i++) {
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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    simulation(0);

    cout << min_dist;

    return 0;
}
