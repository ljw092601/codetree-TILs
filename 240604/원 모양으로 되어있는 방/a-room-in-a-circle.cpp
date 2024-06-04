#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rooms(n,0);
    for(int i=0; i<n; i++) {
        cin >> rooms[i];
    }
    int min_dist = INT_MAX;
    for (int i=0; i<n; i++) {
        int dist = 0;
        for(int p=i; p<i+n; p++) {
            dist += (p-i) * rooms[p%n];
        }
        if(dist < min_dist) min_dist = dist;
    }
    cout << min_dist;
    return 0;
}