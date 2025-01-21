#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[20];
int selected[20];
int max_xor = 0;

void cal_xor() {
    int xor_n = 0;
    for(int i=0; i<n; i++) {
        if(selected[i]) xor_n ^= A[i];
    }
    max_xor = max(max_xor, xor_n);
}

void simulation(int t, int q) {
    if(q == m) {
        cal_xor();
        return;
    }
    if(t == n+1) return;
    selected[t] = 1;
    simulation(t+1, q+1);
    selected[t] = 0;
    simulation(t+1, q);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    simulation(0,0);

    cout << max_xor;

    return 0;
}