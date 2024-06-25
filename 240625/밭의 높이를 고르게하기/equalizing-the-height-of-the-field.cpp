#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n, h, t;
    cin >> n >> h >> t;
    vector<int> field(n,0);
    for(int i=0; i<n; i++) {
        cin >> field[i];
    }
    int min_work = INT_MAX;
    for (int i=0; i<n-t; i++) {
        int work = 0;
        for(int p=0; p<t; p++) {
            work += abs(h - field[i+p]);
        }
        if (work < min_work) min_work = work;
    }
    cout << min_work;
    return 0;
}