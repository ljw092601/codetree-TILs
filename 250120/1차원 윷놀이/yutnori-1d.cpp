#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int nums[12];
int selected[12];
int scores[4];
int max_score = 0;

void clean() {
    for(int i=0; i<4; i++) scores[i] = 0;
}

void cal_score() {
    clean();
    for(int i=0; i<n; i++) {
        scores[selected[i]] += nums[i];
    }
    int score = 0;
    for(int i=0; i<k; i++) {
        if(scores[i] >= m-1) score++;
    }
    // for(int i=0; i<n; i++) cout << selected[i] << ' ';
    // cout << ": " << score << endl;
    max_score = max(max_score, score);
}

void simulation(int t) {
    if(t == n) {
        cal_score();
        return;
    }
    for(int i=0; i<k; i++) {
        selected[t] = i;
        simulation(t+1);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    simulation(0);

    cout << max_score;

    return 0;
}
