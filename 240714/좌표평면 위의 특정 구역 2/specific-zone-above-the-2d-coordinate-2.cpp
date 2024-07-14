#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal_area(const vector<int>& x, const vector<int>& y) {
    auto max_x = max_element(x.begin(), x.end());
    auto min_x = min_element(x.begin(), x.end());
    auto max_y = max_element(y.begin(), y.end());
    auto min_y = min_element(y.begin(), y.end());
    return (*max_x - *min_x) * (*max_y - *min_y);
}

int main() {
    vector<int> x_vec;
    vector<int> y_vec;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x_vec.push_back(x);
        y_vec.push_back(y);
    }
    int min_area = 1600000000;
    for (int i=0; i<n; i++) {
        vector<int> new_x_vec = x_vec;
        vector<int> new_y_vec = y_vec;
        new_x_vec.erase(new_x_vec.begin() + i);
        new_y_vec.erase(new_y_vec.begin() + i);
        int area = cal_area(new_x_vec, new_y_vec);
        if(area < min_area) min_area = area;
    }
    cout << min_area;
    return 0;
}