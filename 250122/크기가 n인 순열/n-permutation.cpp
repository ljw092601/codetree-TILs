#include <iostream>

using namespace std;

int n;
int selected[9];
bool visited[9];

void print() {
    for(int i=0; i<n; i++) cout << selected[i] << ' ';
    cout << endl;
}

void simulation(int k) {
    if(k == n) {
        print();
        return;
    }
    for(int i=1; i<=n; i++) {
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

    simulation(0);

    return 0;
}
