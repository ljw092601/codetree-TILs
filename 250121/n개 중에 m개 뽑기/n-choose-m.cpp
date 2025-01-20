#include <iostream>

using namespace std;

int N, M;
int selected[11];

void print() {
    for(int i=1; i<=N; i++) {
        if(selected[i]) cout << i << ' ';
    }
    cout << endl;
}

void simulation(int k, int q) {
    if(k == N+1) {
        if(q == M) print();
        return;
    }
    selected[k] = 1;
    simulation(k+1, q+1);
    selected[k] = 0;
    simulation(k+1, q);
}

int main() {
    cin >> N >> M;

    simulation(1,0);

    return 0;
}
