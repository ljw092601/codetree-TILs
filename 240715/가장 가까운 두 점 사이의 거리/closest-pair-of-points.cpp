#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cal_dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n;
    cin >> n;
    vector<int> x_vec(n,0);
    vector<int> y_vec(n,0);
    for(int i=0; i<n; i++) {
        cin >> x_vec[i] >> y_vec[i];
    }
    int min_dist = INT_MAX;
    for(int i=0; i<n-1; i++) {
        for(int p=i+1; p<n; p++) {
            int dist = cal_dist(x_vec[i], y_vec[i], x_vec[p], y_vec[p]);
            if (dist < min_dist) min_dist = dist;
        }
    }
    cout << min_dist;
    return 0;
}