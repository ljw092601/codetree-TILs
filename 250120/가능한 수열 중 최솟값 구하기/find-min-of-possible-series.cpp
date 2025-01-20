#include <iostream>

using namespace std;

int n;
int progression[80];
bool finish = false;

void print() {
    for(int i=0; i<n; i++) cout << progression[i];
}

bool is_same_pro(int a, int b) {  // 수열의 시작점 2개
    for(int i=0; i<b-a; i++) {
        if(progression[a+i] != progression[b+i]) return false;
    }
    return true;
}

bool impossible(int cur, int num) {
    progression[cur] = num;
    int size = 1;
    while(size*2 <= cur+1) {
        if(is_same_pro(cur+1-(size*2),cur+1-size)) return true;
        size++;
    }
    return false;
}

void simulation(int k) {
    if (k == n) {
        print();
        finish = true;
        return;
    }

    for(int i=4; i<=6; i++) {
        if(finish) return;
        if(impossible(k, i));
        else {
            progression[k] = i;
            simulation(k+1);
        }
    }
}

int main() {
    cin >> n;

    simulation(0);

    return 0;
}
