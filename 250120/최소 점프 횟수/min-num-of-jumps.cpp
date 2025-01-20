#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[10];
int dist = 0;
int min_jump = 20;

void simulation(int t) {
    if(dist >= n-1) {
        min_jump = min(min_jump, t);
        return;
    }
    for(int i=1; i<=num[dist]; i++) {
        dist += i;
        simulation(t+1);
        dist -= i;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    simulation(0);

    cout << (min_jump == 20 ? -1 : min_jump);

    return 0;
}
