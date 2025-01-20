#include <iostream>

using namespace std;

int K, N;
int selected[9];

void print() {
    for(int i=0; i<N; i++) cout << selected[i] << ' ';
    cout << endl;
}

void simulation(int n) {
    if(n == N) {
        print();
        return;
    }
    for(int i=1; i<=K; i++) {
        if(selected[n-1] == i && selected[n-2] == i);
        else {
            selected[n] = i;
            simulation(n+1);
        }
    }
}

int main() {
    cin >> K >> N;

    simulation(0);

    return 0;
}
