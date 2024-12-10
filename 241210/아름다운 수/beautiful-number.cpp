#include <iostream>
#include <vector>
using namespace std;

int n;
int beautiful_number = 0;
vector<int> number;

void push(int p) {
    for(int i=0; i<p; i++) {
        number.push_back(p);
    }
}

void pop(int p) {
    for(int i=0; i<p; i++) {
        number.pop_back();
    }
}

void make_beautiful() {
    if (number.size() > n) return;
    if (number.size() == n) {
        beautiful_number++;
        for(int k : number) cout << k;
        cout <<endl;
        return;
    }
    for(int i=1; i<=4; i++) {
        push(i);
        make_beautiful();
        pop(i);
    }

}

int main() {
    cin >> n;
    make_beautiful();
    cout << beautiful_number;
    return 0;
}