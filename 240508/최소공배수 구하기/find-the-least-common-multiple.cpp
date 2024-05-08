#include <iostream>
#include <vector>
using namespace std;

int min_mul(int a, int b) {
    vector<int> mul_of_b;
    for (int i=1; i<a+1; i++) {
        mul_of_b.push_back(i * b);
    }
    for (int mb: mul_of_b) {
        if (mb % a == 0) return mb;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    cout << min_mul(n, m);
    return 0;
}