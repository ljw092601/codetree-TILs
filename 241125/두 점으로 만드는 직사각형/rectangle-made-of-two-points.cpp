#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> x(4);
    vector<int> y(4);
    for(int i=0; i<4; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << (x[3] - x[0]) * (y[3] - y[0]);
    return 0;
}