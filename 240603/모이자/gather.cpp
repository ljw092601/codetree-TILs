#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> house;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        house.push_back(num);
    }
    int min = INT_MAX;
    for (int p=0; p<n; p++) {
        int dist = 0;
        for(int q=0; q<n; q++) {
            dist += abs(p-q) * house[q];
        }
        if (dist < min) min = dist;
    }
    cout << min;
    return 0;
}